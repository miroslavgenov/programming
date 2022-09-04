document.querySelector(".grid").addEventListener('click',
        function(e){

           if(e.target.tagName.toUpperCase()==="IMG"){
              var imgCount=this.querySelectorAll('li').length;
              console.log(imgCount);
              if (imgCount>1){

                 e.target.parentNode.remove();
              //   e.target.parentNode.parentNode.removeChild(e.target.parentNode);

              }
              else{
                document.querySelector("#city h2").innerHTML="Вие избрахте град "+e.target.alt;
              }
           }
        }
  );

document.querySelector(".grid").addEventListener("mouseover",
      function(e){
        if (e.target.tagName === 'IMG') {
          var divPrev= document.createElement('div');
          divPrev.className="preview";
          e.target.parentNode.appendChild(divPrev);

        var divImg= document.createElement("img");
        var imgSrc=e.target.src; //src="images/Ruse_tn.jpg"
        divImg.src=imgSrc.substr(0, imgSrc.length-7)+".jpg";
        divPrev.appendChild(divImg);

       
      }
      });

document.querySelector(".grid").addEventListener("mouseout",
            function (e){
                if (e.target.tagName === 'IMG') {
                var divPrev= e.target.parentNode.querySelector("div.preview");
                divPrev.remove();
               
     }
        });