(function(_ds){var window=this;var rW=function(a){a=a.bf;let b;b='<button type="button" class="devsite-recommendations-dropdown-toggle" id="devsite-recommendations-dropdown-toggle" aria-haspopup="true" aria-controls="recommendations-dropdown-popup"><span>Recommended</span><span class="devsite-icon devsite-recommendations-dropdown-icon"></span></button><ul class="devsite-recommendations-dropdown-list devsite-select-list" role="listbox">';const c=a.length;for(let d=0;d<c;d++)b+=qW(a[d]);return(0,_ds.P)(b+"</ul>")},qW=function(a){const b=
[a.Sa(),_ds.y(a,3),_ds.y(a,4)];a='<li role="option" class="devsite-select-item"><h3 class="significatio-card-heading no-link"><a href="'+_ds.T(_ds.W(a.getUrl()))+"?"+_ds.lw(_ds.y(a,8))+'" data-category="Site-Wide Custom Events" data-label="devsite-recommendation card link" data-action="click">'+_ds.R(b.filter(c=>0<(""+_ds.S(c)).length)[0])+'</a></h3><p class="significatio-card-description">'+_ds.R(_ds.Xv(_ds.y(a,5)))+'</p><div class="significatio-card-meta">Updated <span class="significatio-date" date="'+
_ds.T(_ds.Sb(a,_ds.Qz,7).getSeconds())+'"></span></div></li>';return(0,_ds.P)(a)};var sW=function(a){let b;null==(b=a.toggle)||b.classList.remove("active");let c;null==(c=a.o)||c.classList.remove("active")},tW=function(a){a.toggle&&a.eventHandler.listen(a.toggle,"click",()=>{var b;if(null==(b=a.toggle)?0:b.classList.contains("active"))sW(a);else{let d;null==(d=a.toggle)||d.classList.add("active");let e;null==(e=a.o)||e.classList.add("active");if(!a.C){a.C=!0;var c;if(b=null==(c=a.h)?void 0:_ds.fJ(c)){for(const f of b)if(c=_ds.Sb(f,_ds.WI,10))c={targetPage:f.getUrl(),targetType:_ds.Fe(c,
3,0),targetRank:_ds.Pe(c,2),targetIdenticalDescriptions:_ds.Pe(c,4),targetTitleWords:_ds.Pe(c,5),targetDescriptionWords:_ds.Pe(c,6),experiment:_ds.y(c,7)},b={category:"Site-Wide Custom Events",action:"recommended",label:f.getUrl(),nonInteraction:!0,additionalParams:{recommendations:c}},a.dispatchEvent(new CustomEvent("devsite-analytics-observation",{detail:b,bubbles:!0})),c={eventData:JSON.stringify({type:"recommendations",name:"impression",metadata:c})},a.dispatchEvent(new CustomEvent("devsite-analytics-observation-cloudtrack",
{detail:c,bubbles:!0}));a.v.g()}else a.v.j("empty")}}});a.eventHandler.listen(document,"click",b=>{let c;!a.contains(b.target)&&(null==(c=a.toggle)?0:c.classList.contains("active"))&&sW(a)})},uW=class extends _ds.E{constructor(a){super();this.timeZone=a;this.eventHandler=new _ds.H(this);this.toggle=this.o=null;this.g=new _ds.Dk;this.loaded=this.g.promise;this.v=new _ds.Dk;this.C=!1;this.h=null}connectedCallback(){this.eventHandler.listen(document,"devsite-on-recommendations",a=>{a=a.Y;!this.h&&a&&
a.detail&&(2===_ds.Fe(a.detail,5,0)&&(a=a.detail,this.render(a),this.o=this.querySelector(".devsite-recommendations-dropdown-list"),this.toggle=this.querySelector(".devsite-recommendations-dropdown-toggle"),tW(this),this.h=a),this.g.g())})}disconnectedCallback(){_ds.I(this.eventHandler);this.g.j("Disconnected")}render(a){if(this.isConnected){_ds.M(this,rW,{bf:_ds.fJ(a)});a=Array.from(this.querySelectorAll(".significatio-date"));for(const b of a){a=b.getAttribute("date");try{b.textContent=(new Date(1E3*
Number(a))).toLocaleDateString("default",{month:"short",year:"numeric",day:"numeric",timeZone:this.timeZone})}catch(c){}}}}};try{window.customElements.define("devsite-recommendations-dropdown",uW)}catch(a){console.warn("Unrecognized DevSite custom element - DevsiteRecommendationsDropdown",a)};})(_ds_www);
