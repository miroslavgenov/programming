
$(function () {

  /* add navigation triangles to nav links */
  $("#topnav .nav li a").append('<img src="/images/nav-hover-triangle.png"/>');
  $("#subnav .nav li a").append('<img src="/images/subnav-hover-triangle.png"/>');

});

var subnavHeight = undefined;

$(window).on("load", function () {
  updateSubnav();
});

$(window).resize(function() {
  updateSubnav();
});

function updateSubnav() {
  if ($('#subnav').length) {
    var subnavHgt = $('#subnav').height();
    if (subnavHeight === undefined ||
        subnavHeight != subnavHgt) {
      subnavHeight = subnavHgt;
      /* sticky fixed subnavigation menu */
      $('#subnav').affix({
        offset: {
          top: $('#subnav').offset().top
        }
      });
      $('#subnav-wrapper').height(subnavHgt);
      /* observe scroll events and update subnavigation accordingly */
      /* This is offset by an additional 15px */
      /* 10px since we're offset the smoothscroll by 10 and 5px to make sure that the correct subnav item gets selected when scrolling to the top of an anchor */
      $('body').scrollspy({ target: '#subnav', offset: subnavHgt + 15 })
    }
  }
}

/*
$(document).ready(function(){
  var min = 1200;
  $('.jumbotron').each(function(){
    var $jumbo = $(this);
    $(window).resize(function() {
      var bpos = "right top";
      if( $(window).width() < min ) {
        var divw = $('.jumbotron > .container > .row > div').width();

        var bpos = -( min - $(window).width()) + 'px' + ' top';
        console.log("resize to " + $(window).width() + " divw " + divw + " change to coords : " + bpos);
      } 
      $jumbo.css({ backgroundPosition: bpos });  
    }); 
  });
});
*/

var Codebook = {
  // Set to either android, ios, macos, or windows
  defaultPlatform: "ios",

  // Returns either: android, ios, macos, windows, or Codebook.defaultPlatform
  platformForUserAgent: function () {
    var ua = navigator.userAgent.toLowerCase();
    var isAndroid = ua.indexOf("android") > -1;
    var iOSPlatforms = ['iPhone', 'iPad', 'iPod'];
    var platform = "";
    if (navigator.appVersion.indexOf("Win") != -1) {
      platform = "windows";
    } else if(iOSPlatforms.indexOf(window.navigator.platform) !== -1) {
      platform = "ios";
    } else if(navigator.appVersion.indexOf("Mac") != -1) {
      platform = "macos";
    } else if(isAndroid) {
      platform = "android";
    } else {
      platform = Codebook.defaultPlatform;
    }
    // Override here for testing...
    //     platform = "windows";
    return platform;
  },
  getURLParameter: function (name) {
    var searchString = window.location.search.substring(1); // lops off the '?' at the beginning of the string
    var params = searchString.split('&');
    var i, pair;
    for (i = 0; i < params.length; i++) {
      pair = params[i].split('=');
      if (pair[0] === name) {
        // query params can be just a name without a value, in that case return true
        return pair[1] === undefined ? true : decodeURIComponent(pair[1]);
      }
    }
    // Nothing found
    return undefined;
  }
};
