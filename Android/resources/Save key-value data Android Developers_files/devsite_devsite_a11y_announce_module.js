(function(_ds){var window=this;var NK=function(){return"devsite-a11y-announce"},OK=async function(a,b){_ds.ji(a)===b&&(_ds.ci(a,""),await _ds.nj(),await _ds.nj());_ds.ci(a,b)},PK=class extends _ds.E{constructor(){super();this.eventHandler=new _ds.H}connectedCallback(){this.setAttribute("aria-live","assertive");this.setAttribute("aria-atomic","true");this.eventHandler.listen(document.body,"devsite-a11y-announce",a=>{a=a.Y;(a=a.detail&&a.detail.message)&&OK(this,a)})}disconnectedCallback(){_ds.I(this.eventHandler)}};
PK.prototype.connectedCallback=PK.prototype.connectedCallback;PK.getTagName=NK;try{window.customElements.define(NK(),PK)}catch(a){console.warn("Unrecognized DevSite custom element - DevsiteA11yAnnounce",a)};})(_ds_www);
