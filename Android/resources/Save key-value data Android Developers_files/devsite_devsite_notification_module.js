(function(_ds){var window=this;var AU,BU=function(){return"devsite-notification"},CU=function(a){a.dispatchEvent(new CustomEvent("devsite-hide-notification-snackbar-msg",{bubbles:!0}))},DU=class extends _ds.E{constructor(){super(["devsite-snackbar"])}async connectedCallback(){await window.customElements.whenDefined("devsite-snackbar");const a=this.getAttribute("link"),b=this.getAttribute("link-text"),c=this.getAttribute("message");a!==AU&&(!a&&AU?(AU="",CU(this)):a&&c&&(AU&&CU(this),AU=a,this.dispatchEvent(new CustomEvent("devsite-show-notification-snackbar-msg",
{detail:{href:a,linkText:b,msg:c,hidePrevious:"true"},bubbles:!0}))))}};DU.prototype.connectedCallback=DU.prototype.connectedCallback;DU.getTagName=BU;try{window.customElements.define(BU(),DU)}catch(a){console.warn("devsite.app.customElement.DevsiteNotification",a)};})(_ds_www);
