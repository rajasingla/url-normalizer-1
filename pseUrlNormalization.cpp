#include "pseUrlNormalization.h"

PseUrlNormalization::PseUrlNormalization(){
}

PseUrlNormalization::~PseUrlNormalization(){
}

void PseUrlNormalization::to_lower_case(string &word_str){
    //assert(word_str != NULL);
    for(int i = 0; i < word_str.length(); i++){
        word_str[i] = tolower(word_str[i]);
    }
    /*
    register char *p = NULL;
    for (p = word_str ; (*p) ; p++){
        if((*p) >= 'A' &&  (*p) <= 'Z'){
	    (*p) += 'a' - 'A';
	}
    }
    */
}

string &PseUrlNormalization::add_trailing(string &url, size_t &url_len){
    url_len = 0;
    if(url.find_last_of("/") == string::npos){
        url += "/";
        url_len = url.length();
        //return true;
    }
    return url;
}

string &PseUrlNormalization::remove_all(string &url){
    static bool inUrl = false;
    bool done = false;
    //while(!done){
	//char *rule_pattern[4]={"#", ":80", "../", "./"};
	// removing default port
	size_t port_pos = url.find(":80");
	if(port_pos != string::npos){
	    done = true;
	    url.erase(port_pos, 3);
	}
	else{
	    done = false;
	}
        // Above all, being must remove "../" segments before removing "./".
        size_t onedot_current_pos = 0;
        size_t onedot_pos;
        while((onedot_pos = url.find("../", onedot_current_pos)) != string::npos){
            url.erase(onedot_pos, 3);
            onedot_current_pos = onedot_pos;
        }
        // removing "./" segments
        size_t twodot_current_pos = 0;
        size_t twodot_pos;
        while((twodot_pos = url.find("./")) != string::npos){
            url.erase(twodot_pos, 2);
            twodot_current_pos = twodot_pos;
        }
        // removing fragemnet
        size_t fragement_pos = url.find("#");
        if(fragement_pos != string::npos){
            done = true;
	    url.erase(fragement_pos, url.length());
        }
	else{
	    done = false;
	}		
    //}
    return url;
}

string &PseUrlNormalization::remove_www(string &url){
    size_t domain_pos = url.find("www.");
    if(domain_pos != string::npos){
        url.erase(domain_pos, 4);
    }
    return url;
}

/* url_normalizer() normalizes and standardizes the entire url in a consistent manner.
 * The goal of the normalization process is to transform a URL into a normalized or
 * canonical URL so it is possible to determine if two syntactically different URLs
 * are equivalent.
 *
 * The reference is 
 * from http://en.wikipedia.org/wiki/URL_normalization#Normalization_based_on_URL_lists
 * 
 * @param  url     the input URL string
 * @param  url_len the length of input URL
 * @return         if success returns 0, otherwise returns -1.
 **/
bool PseUrlNormalization::url_normalizer(string &url, size_t &url_len){
    /* converting the scheme, host and entire URL to lower case */
    to_lower_case(url);
    /* adding trailing */
    if(add_trailing(url, url_len).empty()){
       cout << "adding trailing slash is failed" << endl;
       return false;
    }
    /* removing the fragement, the default port and dot-segments */
    if(remove_all(url).empty()){
        cout << "removing all of rules is failed" << endl;
	return false;
    } 
    /* removing  "www" the first domain label */
    if(remove_www(url).empty()){
        cout << "removing www is failed" << endl;
	return false;
    }
    return true;
}

