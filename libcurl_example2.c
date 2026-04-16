#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);

struct Memory {
    char *data;
    size_t size;
};

int main() {
    CURL *curl = curl_easy_init();
    CURLcode res;

    struct Memory chunk;
    chunk.data = malloc(1);
    chunk.size = 0;
    
    if (curl) {
        // Set the target URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/users");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Size: %lu\n", (unsigned long)chunk.size);
            printf("Data: %s\n", chunk.data);
        }

        // Always cleanup
        curl_easy_cleanup(curl);
    }

    free(chunk.data);
    return 0;
}

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total = size * nmemb;
    struct Memory *mem = (struct Memory*)userp;

    mem->data = realloc(mem->data, mem->size + total + 1);
    memcpy(&(mem->data[mem->size]), contents, total);
    mem->size += total;
    mem->data[mem->size] = 0;

    return total;
}
