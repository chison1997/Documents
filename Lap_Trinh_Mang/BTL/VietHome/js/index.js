$(document).ready(function() {
  var checkBrowser ;

  if ((!!window.opr && !!opr.addons) || !!window.opera || navigator.userAgent.indexOf(' OPR/') >= 0)
  {
    checkBrowser = "Opera";
  } 
  else if(typeof InstallTrigger !== 'undefined'){
    checkBrowser = "FireFox";
  }
  else if(/constructor/i.test(window.HTMLElement) || (function (p) { return p.toString() === "[object SafariRemoteNotification]"; })(!window['safari'] || safari.pushNotification)) {
    checkBrowser = "SafaRi";
  } 
  else if(/*@cc_on!@*/false || !!document.documentMode) {
    checkBrowser = "Internet Explorer";
  } 
  else if(!(/*@cc_on!@*/false || !!document.documentMode) && !!window.StyleMedia) {
    checkBrowser = "Edge";
  } 
  else if(!!window.chrome && !!window.chrome.webstore) {
    checkBrowser = "Chrome";
  }
  else {
    checkBrowser = "undefined";
  }

  $.ajax({
    type: 'POST',
    url: '/checkbrowser',
    dataType: "json",
    data: {
      checkBrowser
    },
  });

});

var search = [];
search['coccoc'] = 'http://coccoc.com/search#query=';
search['google'] = 'https://www.google.com.vn/search?espv=2&q=';
search['yahoo'] = 'https://vn.search.yahoo.com/search?p=';
color = '#456';
if (localStorage.note == null) {
  localStorage.note = '';
}

if (localStorage.theme == null) {
  localStorage.theme = 'white';
}

if (localStorage.searcher == null) {
  localStorage.wallpaper = 'img/bg.png';
  localStorage.searcher = 'google';
  localStorage.topsite = 'block';
} else {
  if (localStorage.v3 != "true") {
    localStorage.v3 = "true";
  }
}
if (localStorage.app == null) {
  localStorage.app = document.getElementById('appde').innerHTML;
}
document.getElementById('bgver3').addEventListener("click", function () { document.getElementById('bgver3').style.display = "none"; });

if (localStorage.topsite == 'block') {
  document.getElementById('checktop').checked = true;
} else {
  document.getElementById('topsite').style.display = "none";
}


//theme
var cssId = 'myCss';
if (!document.getElementById(cssId)) {
  var head = document.getElementsByTagName('head')[0];
  var link = document.createElement('link');
  link.id = cssId;
  link.rel = 'stylesheet';
  link.type = 'text/css';
  link.href = 'css/' + localStorage.theme + '.css';
  link.media = 'all';
  // head.appendChild(link);
}

//simple
if (localStorage.simplemode == 'true') {
  document.getElementById('checksimple').checked = true;
  simplemode();
} else {

}

function simplemode() {
  document.getElementById('checktop').checked = true;
  document.getElementById("logosearch").style.display = "none";
  document.getElementsByClassName("searchinput")[0].style.display = "none";
  document.getElementById("topsite").style.display = "none";
  document.getElementById("website").style.background = "none";
  localStorage.topsite = "hidden";

  console.log("simplemode");
}
function dissimplemode() {
  document.getElementById("logosearch").style.display = "block";
  document.getElementsByClassName("searchinput")[0].style.display = "block";
  document.getElementById("topsite").style.display = "block";
  document.getElementById("website").setAttribute("style", "");
  localStorage.topsite = "block";

}

document.getElementById('checksimple').addEventListener("change", function () {
  if (document.getElementById('checksimple').checked == true) {
    simplemode();
    localStorage.simplemode = 'true';
  } else {
    localStorage.simplemode = 'false';
    dissimplemode();
  }
});
//seacher
document.getElementById('logosearch').style.backgroundImage = 'url("img/' + localStorage.searcher + '.png")';
//
for (c = 0; c < document.getElementsByClassName('color').length; c++) {
  document.getElementsByClassName('color')[c].addEventListener("click", function (event) {
    color = event.srcElement.title;
  });
}
document.body.style.backgroundImage = "url('" + localStorage.wallpaper + "')";
document.getElementById('searcher').value = localStorage.searcher;
document.getElementById('addwall').addEventListener("click", function () {
  document.getElementById('inwall').click();
});
document.getElementById('searcher').addEventListener("change", function () {
  localStorage.searcher = document.getElementById('searcher').value;
  document.getElementById('logosearch').style.backgroundImage = 'url("img/' + localStorage.searcher + '.png")';
});
document.getElementById('inwall').addEventListener("change", function () {
  var file = document.getElementById('inwall').files[0];
  var reader = new FileReader();

  reader.addEventListener("load", function () {
    document.body.style.backgroundImage = "url('" + reader.result + "')";
    localStorage.wallpaper = reader.result;
  }, false);

  if (file) {
    reader.readAsDataURL(file);
  }
});
document.getElementsByClassName('setbtn')[0].addEventListener("click", function () {
  document.getElementById('set').style.right = "0";
});
document.getElementById('close').addEventListener("click", function () {
  document.getElementById('set').style.right = "-100%";
});
document.getElementById('closeedit').addEventListener("click", function () {
  document.getElementById('editpop').style.right = "-100%";
});
for (i = 0; i <= 6; i++) {
  document.getElementsByTagName('img')[i].addEventListener("click", function (event) {
    localStorage.wallpaper = event.srcElement.title;
    document.body.style.backgroundImage = "url('" + event.srcElement.title + "')";
  });
}

document.body.addEventListener("click", function () {
  hideauto();
});
document.getElementById('searchbtn').addEventListener("click", function () {
  location.href = search[localStorage.searcher] + document.getElementById('input').value;
});
document.getElementById('input').addEventListener("keyup", function (event) {
  if (event.keyCode == 13) {
    document.getElementById('searchbtn').click();
  }
});
document.getElementById('checktop').addEventListener("click", function () {
  if (document.getElementById('checktop').checked == true) {
    document.getElementById('topsite').style.display = "block";
    localStorage.topsite = 'block';
  } else {
    document.getElementById('topsite').style.display = "none";
    localStorage.topsite = 'hidden';
  }
});


changescreen();
function changescreen() {
  document.getElementById('web').innerHTML = localStorage.app;
  var wwidth = document.getElementById('website').getElementsByTagName('figure').length * (document.getElementById('website').getElementsByTagName('figure')[0].offsetWidth + 8);
  if ((wwidth + 20) > window.innerWidth) {
    document.getElementById('style').innerHTML = "#website a{zoom:" + (window.innerWidth - 75) / wwidth + ";}";
  } else {
    document.getElementById('style').innerHTML = "#website a{zoom:1;}";
  }
}
window.addEventListener("resize", function () {
  changescreen();
});
document.getElementsByClassName('del')[0].addEventListener("click", function () {
  innerdel();
  document.getElementById('doneweb').style.display = 'block';
});
document.getElementById('doneweb').addEventListener("click", function () {
  document.getElementById('editdiv').innerHTML = '';
  document.getElementById('doneweb').style.display = 'none';
  document.getElementById('addweb').style.display = 'block';
});
function innerdel() {
  document.getElementById('addweb').style.display = 'none';
  document.getElementById('editdiv').innerHTML = "<h4>Chắc Chắn Xóa</h4>" + document.getElementById('web').innerHTML;
  for (k = 0; k < document.getElementById('editdiv').getElementsByTagName('a').length; k++) {
    document.getElementById('editdiv').getElementsByTagName('a')[k].removeAttribute("href");
    document.getElementById('editdiv').getElementsByTagName('a')[k].title = k;
    document.getElementById('editdiv').getElementsByTagName('a')[k].getElementsByTagName('figcaption')[0].title = k;
    document.getElementById('editdiv').getElementsByTagName('a')[k].getElementsByTagName('figure')[0].title = k;
    document.getElementById('editdiv').getElementsByTagName('a')[k].getElementsByTagName('img')[0].title = k;
    document.getElementById('editdiv').getElementsByTagName('a')[k].addEventListener("click", function (ev) {
      document.getElementById('web').getElementsByTagName('a')[ev.srcElement.title].remove();
      innerdel();
      localStorage.app = document.getElementById('web').innerHTML;
      changescreen();
    });
  }
}
document.getElementById('addbtn').addEventListener("click", function () {
  google = "https://plus.google.com/_/favicon?domain_url=";
  if (document.getElementById('title').value.length > 13) {
    title = document.getElementById('title').value.substring(0, 10) + '...';
  } else {
    title = document.getElementById('title').value;
  }
  document.getElementById('web').innerHTML = document.getElementById('web').innerHTML + "<a href='" + document.getElementById('link').value + "' ><figure><img src='img/img.png' style='background-color:" + color + ";background-image:url(&#39;" + document.getElementById('gg').value + document.getElementById('link').value + "&#39;)'><figcaption>" + title + "</figcaption> </figure></a>";
  localStorage.app = document.getElementById('web').innerHTML;
  document.getElementById('web').innerHTML = localStorage.app;
  changescreen();
  document.getElementById('title').value = '';
  document.getElementById('link').value = '';
});
document.getElementById('editbtn').addEventListener("click", function () {
  document.getElementById('editpop').style.right = "0";
});
document.getElementById('bookmark').addEventListener("click", function () {
  chrome.tabs.update({ url: "chrome://bookmarks/" })
});
document.getElementById('settingbtn').addEventListener("click", function () {
  document.getElementById('set').style.right = "0";
});


document.getElementById('input').addEventListener("keyup", function () {
  if (document.getElementById('input').value.length > 0) {
    document.getElementsByClassName('searchinput')[0].style.borderRadius = "4px 4px 0 0";
    loadauto(document.getElementById('input'));
    document.getElementById('searchbtn').style.borderRadius = "0 4px 0 0";
    displayauto();
  } else {
    document.getElementsByClassName('searchinput')[0].style.borderRadius = "10px 25px 25px 10px";
    document.getElementById('searchbtn').setAttribute("style", "");
    hideauto();
  }

});




function loadauto(elem) {
  var url = 'https://www.google.com/complete/search?client=firefox&hl=vi&callback=auto&q=' + elem.value;
  var jsonFile = new XMLHttpRequest();
  jsonFile.open("GET", url, true);
  jsonFile.send();
  jsonFile.onreadystatechange = function () {
    if (jsonFile.readyState == 4 && jsonFile.status == 200) {

      json = jsonFile.responseText;
      json = json.substring(json.indexOf('['), json.lastIndexOf(']'));
      json = json.substring(1, json.length);
      json = json.substring(json.indexOf('[') + 2, json.length - 2);
      auto(json.split('","'));
    }
  }
}
function auto(data) {
  console.log(data);
  if (data[0] != '[]') {
    document.getElementById("auto").innerHTML = '';
    if (data.length < 4) { maxk = data.length } else { maxk = 4 }
      for (k = 0; k < maxk; k++) {
        document.getElementById("auto").innerHTML += "<a href=" + encodeURI(search[localStorage.searcher] + data[k]) + " ><span>" + data[k] + "</span><a>";
      }
    } else {
      document.getElementById("auto").innerHTML = '';
      hideauto();
    }
  }



  function hideauto() {
    document.getElementById('auto').style.display = "none";
    if (localStorage.topsite == 'block') {
      document.getElementById('topsite').style.display = "block";
    } else {
      document.getElementById('topsite').style.display = "none";
    }
  }
  function displayauto() {
    document.getElementById('auto').style.display = "block";
    document.getElementById('topsite').style.display = "none";
  }
  function addnote() {
    if (document.getElementById('noteip').value.length > 1) {
      localStorage.note = '<div class="note"><i class="fa fa-check" aria-hidden="true"></i> &nbsp;' + document.getElementById('noteip').value + '</div>' + localStorage.note;
      document.getElementById('noteip').value = ''
      loadnote();
    }
  }

  document.querySelector('#noteip').addEventListener('keypress', function (e) {
    var key = e.which || e.keyCode;
    if (key === 13) {
      addnote();
    }
  });

  function loadnote() {
    document.getElementById('notedisplay').innerHTML = localStorage.note;
    if (localStorage.note.length < 4) { document.getElementById('notedisplay').innerHTML = '<br><center><h2>Báº¡n khĂ´ng cĂ³ nháº¯c nhá»Ÿ nĂ o</h2>' }
      display = document.getElementById('notedisplay');
    for (i = 0; i < display.getElementsByClassName('note').length; i++) {
      display.getElementsByClassName('note')[i].addEventListener('click', function (e) {
        e.target.remove();
        localStorage.note = document.getElementById('notedisplay').innerHTML;
        if (localStorage.note.length < 4) { document.getElementById('notedisplay').innerHTML = '<br><center><h2>Báº¡n khĂ´ng cĂ³ nháº¯c nhá»Ÿ nĂ o</h2>' }
      });
    }

  }
  loadnote();
  document.getElementsByClassName('notebtn')[0].addEventListener("click", function () {
    if (document.getElementById('note').style.right != '0px') {
      document.getElementById('note').style.right = "0px";
      document.getElementById('noteip').focus();
    } else { document.getElementById('note').style.right = "-400px"; }
  });


  for (t = 0; t < document.getElementsByClassName('colort').length; t++) {
    document.getElementsByClassName('colort')[t].addEventListener("click", function (event) {
      localStorage.theme = event.srcElement.title;
      location.reload();
    });
  }

  document.querySelector('#reset').addEventListener('click', function () {
    if (confirm("Bạn có chắc muốn khôi phục mặc định không ?")) {
      localStorage.clear();
      location.reload();
    }

  });