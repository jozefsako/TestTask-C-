#include <iostream>
#include <string>
#include <stdio.h>
#include <curl/curl.h>

void fetchData();

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
  std::string menu = "\n\n-------------Menu-------------\n\n1) FetchData()\n2) Exit()\n\nEnter your choice : ";
  std::cout << menu;
  
  int choice;

  /* Read Your Choice */
  std::cin >> choice;

  while(choice != 0)
  {
    switch (choice)
    {
    case 1:
      fetchData();
      break;
    
    case 2:
      std::cout << "\nExit ...\n";
      exit(0);
      break;
    }

    /* Enter Your Choice Again */
    std::cout << menu;
    std::cin >> choice;
  }

  return 0;
}

void fetchData()
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();

  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.ipify.org?format=json");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;
  }
}