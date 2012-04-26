var except='\
10.*.*.*;\
192.168.*.*\
'.split(";");

var rules='\
*.appspot.com;\
*.bestvideodownloader.com;\
*.blogspot.com;\
*.code.google.com;\
*.cosmicencounter.com;\
*.docs.google.com;\
*.facebook.com;\
*.fbcdn.net;\
*.feedburner.com;\
*.geekdo-images.com;\
*.googleusercontent.com;\
*.libimobiledevice.org;\
*.mail-archive.com;\
*.nabble.com;\
*plus.google.com;\
*.t.co;\
*.twitbrowser.net;\
*twitter.com;\
*.wordpress.com;\
*.youtube.com;\
*.ytimg.com;\
*.google.com\
'.split(';');

init_rules();

function init_rules() {
  for(i in rules) {
    rules[i] = rules[i].replace(/\./g,"\\.");
    rules[i] = rules[i].replace(/\*/g,".*");
  }
  for(i in except){
    except[i] = except[i].replace(/\./g,"\\.");
    except[i] = except[i].replace(/\*/g,".*");
  }
}

function gfwed(url) {
  for(i in rules) {
    if(url.match(rules[i]))
      return true;
  }
  return false;
}

function exp(url) {
  for(i in except) {
    if(url.match(except[i]))
      return true;
  }
  return false;
}

function FindProxyForURL(url, host) {
  if (exp(url)) {
    return "DIRECT";
  } else if (gfwed(url)) {
    return "PROXY 127.0.0.1:8086;";
  } else {
    return "DIRECT";
  }
}
