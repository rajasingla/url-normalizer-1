#include "pseUrlNormalization.h"

using namespace std;

int main(void){
    string url = "http://www.KIMO.com.TW:80/../a/b/../c/./home.htm#section1";
    size_t    url_len = url.length();
    cout << "before adding trailing slash" << endl;
    //cout << "new url:" << url << endl;
    cout << "url length:" << url_len << endl;
    
    PseUrlNormalization normalizer;
/*
    if(!normalizer.add_trailing(url, url_len).empty()){
       cout << "adding trailing is failed" <<  endl;     
    }
    cout << "After adding trailing slash" << endl;
    cout << "new url:" << url << endl;
    cout << "new url length:" << url_len << endl;
    if(!normalizer.remove_all(url).empty()){
        cout << "after removing" << endl;
        cout << url << endl;
    }
    if(!normalizer.remove_www(url).empty()){
        cout << "after removing www:" << url << endl;
    }
*/
    if(normalizer.url_normalizer(url, url_len) == true){
        cout << "new url:" << url << endl;
        cout << "new url length:" << url_len << endl;
    }
}

