(function(_ds){var window=this;var OT=_ds.VC(['button:after,button:before{-moz-osx-font-smoothing:grayscale;text-rendering:optimizeLegibility;text-transform:none;word-wrap:normal;color:var(--devsite-secondary-text-color)}:host{display:block;position:relative}*{-moz-box-sizing:border-box;box-sizing:border-box}[hidden]{display:none}button{-moz-appearance:none;-webkit-appearance:none;-webkit-box-align:center;-webkit-align-items:center;-moz-box-align:center;-ms-flex-align:center;align-items:center;background-color:var(--devsite-select-background-color);border:var(--devsite-select-border,var(--devsite-secondary-border));border-radius:var(--devsite-select-border-radius);box-shadow:none;color:var(--devsite-select-color,var(--devsite-primary-text-color));cursor:pointer;display:-webkit-box;display:-webkit-flex;display:-moz-box;display:-ms-flexbox;display:flex;font:var(--devsite-select-font,500 14px/36px var(--devsite-primary-font-family));height:36px;max-width:154px;outline:0;padding-block:0;padding-inline:11px 7px;-webkit-transition:background-color .2s;transition:background-color .2s}button:is(:hover,:focus){background:var(--devsite-select-background-color-hover,var(--devsite-background-3))}button:before{font:24px Material Icons;-webkit-font-feature-settings:"liga";-moz-font-feature-settings:"liga";font-feature-settings:"liga";-webkit-font-smoothing:antialiased;content:"language"/"";margin-inline:0 8px}button:after{font:24px Material Icons;-webkit-font-feature-settings:"liga";-moz-font-feature-settings:"liga";font-feature-settings:"liga";-webkit-font-smoothing:antialiased;content:"arrow_drop_down"/""}button>span{overflow:hidden;text-overflow:ellipsis;white-space:nowrap}[role=menu]{background:var(--devsite-background-1);border:var(--devsite-list-border,var(--devsite-secondary-border));border-radius:var(--devsite-list-border-radius,2px);box-shadow:0 1px 2px 0 var(--devsite-elevation-key-shadow-color),0 2px 6px 2px var(--devsite-elevation-ambient-shadow-color);inset-inline:var(--devsite-language-selector-menu-inset-inline,0 auto);max-height:304px;overflow:hidden auto;padding:8px 0;position:absolute;top:36px;-webkit-transform:var(--devsite-language-selector-menu-transform);transform:var(--devsite-language-selector-menu-transform);z-index:1}']);var PT=function(a){a.h=[...a.querySelectorAll("a")];a.J=a.h.length-1;const b=_ds.F(),c=new URLSearchParams(b.search);for(const d of a.h){a=d.getAttribute("lang");const e=a.toLowerCase().replaceAll("_","-");_ds.xc([(0,_ds.u)`lang`],d,"lang",e);"en"!==a&&c.set("hl",e);b.search=c.toString();_ds.Qc(d,_ds.Pc(b.href))}},QT=async function(a){if(a.g.get("django_language")){var b;const c=null==(b=a.querySelector("[aria-current]"))?void 0:b.textContent;c&&(a.Cc=c)}else b=await _ds.x(),a.g.set("django_language",
b.getLocale()||"en",{Xb:15552E3,path:"/"}),(a=a.querySelector('[lang="en"]'))&&_ds.xc([(0,_ds.u)`aria-`],a,"aria-current","true")},RT=async function(a){const b=a.g.get("django_language");b&&await a.X.set("language_preference",b)},ST=function(a){a.eventHandler.listen(document.body,"click",b=>{b.target!==a&&(a.open=!1,_ds.I(a.eventHandler))});a.eventHandler.listen(document.body,"keydown",b=>{"Escape"===b.key&&(a.open=!1,_ds.I(a.eventHandler),a.toggle.focus())})},TT=async function(a,b,c){a.dispatchEvent(new CustomEvent("devsite-analytics-observation",
{detail:{category:"Site-Wide Custom Events",label:"Language Selector",action:`${b} to ${c}`},bubbles:!0}));b={eventData:JSON.stringify({name:"change",type:"languageSelector",metadata:{"selected-language":`${c}`,"original-language":`${b}`}})};a.dispatchEvent(new CustomEvent("devsite-analytics-observation-cloudtrack",{detail:b,bubbles:!0}))},UT=async function(a,b){const c=b.target.getAttribute("lang");c&&(b.stopPropagation(),await _ds.x(),a.g.remove("django_language"),a.g.set("django_language",c,{Xb:15552E3,
path:"/"}),(b=document.documentElement.getAttribute("lang"))&&await TT(a,b,c),await RT(a),a=new URL(_ds.Nh().location.toString()),a.searchParams.delete("hl"),a=_ds.Pc(a.toString()),_ds.Nh().location.assign(_ds.Fc(a)))},VT=class extends _ds.sD{constructor(){super(...arguments);this.g=new _ds.ou;this.eventHandler=new _ds.H;this.h=[];this.J=0;this.X=_ds.rl();this.ariaLabel="Select your language preference.";this.open=!1;this.Cc="Language"}static get Zb(){return OT}async Mc(){PT(this);try{await QT(this),
await RT(this)}catch(a){}}async M(){if(this.open=!this.open){await this.H;let a;null==(a=this.querySelector("[aria-current]"))||a.focus();ST(this)}else _ds.I(this.eventHandler)}render(){return(0,_ds.X)`
      <button type="button"
              aria-controls="language-menu"
              aria-haspopup="true"
              @click="${this.M}">
        <span>${this.Cc}</span>
      </button>
      <div id="language-menu"
           role="menu"
           @click="${a=>void UT(this,a)}"
           @keydown="${a=>{if("ArrowUp"===a.key||"ArrowDown"===a.key){a.preventDefault();let b=0;const c=document.activeElement;c&&(b=this.h.indexOf(c));b="ArrowUp"===a.key?0===b?this.J:b-1:b===this.J?0:b+1;this.h[b].focus()}}}"
           ?hidden=${!this.open}>
        <slot></slot>
      </div>`}qb(a){if(a&&(a=a.querySelector("ul"))){let b;null==(b=this.querySelector("ul"))||b.remove();this.append(a);PT(this);_ds.gD(this)}}};_ds.B([_ds.Zo({type:String,Ea:"aria-label",Ya:!0}),_ds.C(Object)],VT.prototype,"ariaLabel",void 0);_ds.B([_ds.Zo({type:Boolean,Ya:!0}),_ds.C(Object)],VT.prototype,"open",void 0);_ds.B([_ds.dp(),_ds.C(Object)],VT.prototype,"Cc",void 0);_ds.B([_ds.cp("button"),_ds.C(HTMLButtonElement)],VT.prototype,"toggle",void 0);try{window.customElements.define("devsite-language-selector",VT)}catch(a){console.warn("devsite.app.customElement.DevsiteLanguageSelector",a)};})(_ds_www);
