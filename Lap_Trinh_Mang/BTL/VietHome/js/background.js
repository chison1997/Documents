function check(){
    count=localStorage.note.split('"note"').length-1;
    if(count>0){
        chrome.browserAction.setBadgeBackgroundColor({color: [222, 22, 0, 0]});
        chrome.browserAction.setBadgeText({text: ''+count});
    }else{
        chrome.browserAction.setBadgeText({text: ''});
    }
setTimeout(function(){check()},200);
}
check();
