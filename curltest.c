#include <stdio.h>
#include <curl/curl.h>

// this program takes command line arguments
int main(int argc, char **argv){
	CURL *c;
	CURLcode res;
	char id[20], mail[40], poststr[100];

	if(argc < 3){
		printf("Usage: %s [ID] [email]\n", argv[0]);
		return 1;	// program stops because the user has not given enough info
	}

	sprintf(poststr, "ID=%s&mail=%s", argv[1], argv[2]);
	curl_global_init(CURL_GLOBAL_ALL);
	c = curl_easy_init();
	if(c){
		curl_easy_setopt(c, CURLOPT_URL, "http://www.cc.puv.fi/~e1800948/curl.php");
		curl_easy_setopt(c, CURLOPT_POSTFIELDS, poststr);//"ID=1800948&mail=oab.uv9@gmail.com")
		res = curl_easy_perform(c);
		if(res != CURLE_OK)
      			printf("Error in curl_easy_perform().\n");
		else 
			printf("Post data is sent\n");
 
		curl_easy_cleanup(c);
	}
	curl_global_cleanup();
	return 0;
}
