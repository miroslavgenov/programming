var div=document.getElementById("d1");

function checkEvent(e){
	
	if(e.type=="click") {
		move(e.clientY, e.clientX);
	}

	if(e.type=="keydown"){
		var style= getComputedStyle(div);
		var currentTop= style.top;
		var currentLeft= style.left;
		switch(e.key){
			case "ArrowLeft":
			  move(parseInt(currentTop), parseInt(currentLeft)-50);
			  break;
			case "ArrowUp":
			  move(parseInt(currentTop)-50, parseInt(currentLeft));
			  break; 
			case "ArrowRight":
			  move(parseInt(currentTop), parseInt(currentLeft)+50);
			  break;
			case "ArrowDown":
			  move(parseInt(currentTop)+50, parseInt(currentLeft));
			  break; 
	  }
	}
}	
	
function move(top, left){
	div.style.top= top+"px";
    div.style.left= left+"px";

}

document.addEventListener("click",checkEvent);
document.addEventListener("keydown",checkEvent);
