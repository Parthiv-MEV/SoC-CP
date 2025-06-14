//review again later
string simplifyPath(string path) {
    vector<string> stack;
    int i = 0;
    int n = path.length();

    while (i < n) {
        while (i < n && path[i] == '/') i++;

        string temp = "";
        while (i < n && path[i] != '/') {
            temp += path[i];
            i++;
        }

        if (temp == "" || temp == ".") {
            continue;
        } else if (temp == "..") {
            if (!stack.empty()) stack.pop_back(); 
        } else {
            stack.push_back(temp); 
        }
    }

    string result = "/";
    for (int j = 0; j < stack.size(); j++) {
        result += stack[j];
        if (j != stack.size() - 1) result += "/";
    }

    return result;
}