$(window).on('load', function() {
  /* smooth scrolling to anchor links */
  $('a[href*="#"]:not([href="#"],[data-toggle="tab"])').click(function() {
    if (location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && location.hostname == this.hostname) {
      var target = $(this.hash);
      target = target.length ? target : $('[name=' + this.hash.slice(1) +']');
      if (target.length) {
        var navAdj = 0;
        if ($('#subnav').length) { /* if subnav present, adjust scroll to by height */
          navAdj = $('#subnav').height();
        }
        $('html,body').animate({
          /* Add Extra 10px kludge so the item doens't hugh right up against the subnav/top of the window */
          scrollTop: target.offset().top - navAdj - 10
        }, 750);
        window.location.hash = this.hash;
        return false;
      }
    }
  });
  /* on window ready smoothscroll to the anchor hash if there is one */
  /* This will account for the nav bar height whereas the standard behavior doesn't */
  if (window.location.hash) {
    smoothScrollToAnchor(window.location.hash, false);
  }
});

function smoothScrollToAnchor(anchorId, animate) {
  var animationTime = animate ? 750 : 0;
  var navAdj = 0;
  if ($('#subnav').length) { /* if subnav present, adjust scroll to by height */
    navAdj = $('#subnav').height();
  }
  $('html,body').animate({
    /* Add Extra 10px kludge so the item doens't hugh right up against the subnav/top of the window */
    scrollTop: $(anchorId).offset().top - navAdj - 10
  }, animationTime);
};

/* handles not accounting for nav bar height when the hash changes */
$(window).on('hashchange', function(event) {
  if (window.location.hash) {
    smoothScrollToAnchor(window.location.hash, false);
  }
});