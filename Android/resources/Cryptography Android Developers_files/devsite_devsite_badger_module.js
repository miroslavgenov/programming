(function(_ds){var window=this;var QM=function(a){var b=a.Qa;a=a.ib;return(0,_ds.P)('<div class="devsite-badger-award-inner"><devsite-badge-awarded badge-name="'+_ds.T(b.title)+'" badge-icon-url="'+_ds.T(_ds.W(b.imageUrl))+'" badge-url="'+_ds.T(_ds.W(b.url))+'"'+(null!=b.currentTierCount?' badge-count="'+_ds.T(b.currentTierCount)+'"':"")+(null!=b.complete?' badge-complete="'+_ds.T(b.complete)+'"':"")+(null!=b.isNewTier?' is-new-tier="'+_ds.T(b.isNewTier)+'"':"")+(b.path?' badge-path="'+_ds.T(b.path)+'"':"")+(b.shareTitle?' badge-share-title="'+
_ds.T(b.shareTitle)+'"':"")+(b.shareDescription?' badge-share-description="'+_ds.T(b.shareDescription)+'"':"")+(b.nextPlaylistUrl?' next-playlist-url="'+_ds.T(_ds.W(b.nextPlaylistUrl))+'"':"")+(b.redeemAnotherBtn?" redeem-another":"")+(b.hideButtons?" hide-buttons":"")+(b.redeemCode?' redeem-code="'+_ds.T(b.redeemCode)+'"':"")+(a?' return-uri="'+_ds.T(_ds.W(a))+'"':"")+" dismiss></devsite-badge-awarded></div>")},RM=function(){return(0,_ds.P)('<div class="devsite-badger-award"></div>')};var SM=/\/redeem.*|\/u[\/]?.*|\/settings[\/]?.*?/,WM=function(a){a.eventHandler.listen(document.body,"devsite-before-page-change",()=>void TM(a));a.eventHandler.listen(document.body,"devsite-award-granted",b=>{(b=b.Y)&&b.detail&&UM(a,b.detail.award)});a.eventHandler.listen(document.body,["devsite-page-loaded","devsite-page-changed"],()=>{a.Yd();VM(a)})},TM=async function(a){if(a.g){var b=a.g.querySelectorAll(".devsite-badger-award-inner"),c=b[0];if(c){const d=c.querySelector("devsite-badge-awarded");
if(null==d?0:d.h)null==d||d.h();const e=null==d?void 0:d.getAttribute("badge-path");a.eb=a.eb.filter(f=>f.path!==e);c.removeAttribute("show");await _ds.nj(200);_ds.Uh(c);1===b.length&&(_ds.Uh(a.g),a.g=null)}}},UM=async function(a,b){if(b&&b.complete&&!a.eb.find(f=>f.path===b.path)&&"error"!==document.body.getAttribute("type")&&!SM.exec(document.location.pathname)){a.eb.push(b);if(!a.g){var c=document.querySelector(".static-badge-awarded-container");c?(a.g=c,a.h=!0):(a.g=_ds.N(RM),document.body.appendChild(a.g))}try{await window.customElements.whenDefined("devsite-badge-awarded")}catch(f){}var d;
c=null==(d=_ds.ij())?void 0:d.href;var e=_ds.N(QM,{Qa:b,ib:c});e&&(a.eventHandler.listen(e,"devsite-badge-awarded-dismissed",()=>{TM(a)}),d=e.querySelector("devsite-badge-awarded"))&&(a.g.appendChild(e),_ds.Bk(a.eventHandler,d,"running",()=>{null==e||e.setAttribute("show","");var f;const g=null==(f=a.g)?void 0:f.querySelectorAll("devsite-badge-awarded");if(g&&!a.h)for(f=0;f<g.length;f++){let h;null==(h=g[f])||h.dispatchEvent(new CustomEvent("devsite-badge-awarded-stack-num-changed",{bubbles:!0,detail:{Dp:g.length-
1-f}}))}}))}},VM=function(a){if(_ds.jm(a.storage)){var b=_ds.XE();if(b){b=b.filter(c=>3>c.displayCount);0<b.length?a.storage.set("temp_badges",JSON.stringify(b)):a.storage.remove("temp_badges");for(const c of b){b=new URL(c.awardedBy,document.location.origin);const d=_ds.F();(!c.awardedBy||b.origin===d.origin&&b.pathname===d.pathname)&&c.complete&&UM(a,c)}}}},XM=class extends _ds.fF{constructor(){super(["devsite-badge-awarded"]);this.eventHandler=new _ds.H(this);this.storage=new _ds.km;this.g=null;
this.eb=[];this.h=!1}connectedCallback(){WM(this)}disconnectedCallback(){_ds.I(this.eventHandler);TM(this)}async Yd(){await _ds.x();await window.customElements.whenDefined("devsite-user");var a=document.querySelector("devsite-user#devsite-user");if(a){var b=!1;try{b=await a.isSignedIn()}catch(c){}if(b&&await (new _ds.Fv).Ec()){a=new _ds.Bv;try{await a.oa()}catch(c){}}}}};try{window.customElements.define("devsite-badger",XM)}catch(a){console.warn("Unrecognized DevSite custom element - DevsiteBadger",a)};})(_ds_www);
