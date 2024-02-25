#include<stdio.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<string.h>

char *url = NULL;

// struct for holding http response.
struct memory_struct{
    char   *buffer;
    size_t size;
};

// write response data to the memory buffer.
static size_t
mem_write(void *contents, size_t size, size_t nmemb, void *userp){
    // initialize memory_struct
    size_t realsize = size * nmemb;
    struct memory_struct *mem = (struct memory_struct *)userp;
    
    char *ptr = realloc(mem->buffer, mem->size + realsize + 1);
    if(ptr == NULL) {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    // copy the response contents to memory_struct buffer.
    mem->buffer = ptr;
    memcpy(&(mem->buffer[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->buffer[mem->size] = 0;

    // return the size of content that is copied.
    return realsize;
}

void http_get(char *url, struct memory_struct *mem){
    CURL *curl_handle;
    CURLcode res;
    
    mem->buffer = malloc(1);
    mem->size   = 0;
    
    curl_global_init(CURL_GLOBAL_ALL);

    // initialize curl
    curl_handle = curl_easy_init();

    // specify url, callback function to receive response, buffer to hold
    // response and lastly user agent for http request.
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, mem_write);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)mem);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "custom-agent");
 
    // make the http request.
    res = curl_easy_perform(curl_handle);
 
    // check for errors.
    if(res != CURLE_OK){
        fprintf(stderr, "curl_easy_perform() failed: %s\n", 
                curl_easy_strerror(res));
    }
 
    // cleanup
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
}

char* request(char *url){

    printf("trying to make http request to: %s\n", url);
    struct memory_struct m;
    http_get(url, &m);

    char *result = malloc(sizeof(m.buffer));
    
    printf("File written.\n"); 
    
    
    size_t sizeOfBuffer = sizeof(m.buffer);

    memcpy(result, m.buffer, sizeOfBuffer);

    return result;
  
}
