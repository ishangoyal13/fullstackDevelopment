function getAnupdate(){
    var t = document.getElementById("tittletexe").value;
    var d = document.getElementById("listheading").value;


    if(localStorage.getItem('Rohit Pandey') == null){
        Rohit=[];
        Rohit.push([t,d]);
        localStorage.setItem('Rohit Pandey',JSON.stringify(Rohit));
        }
    else{
       Rohitstr = localStorage.getItem('Rohit Pandey');
       Rohit = JSON.parse(Rohitstr); 
       Rohit.push([t,d]);
       localStorage.setItem('Rohit Pandey',JSON.stringify(Rohit));
    }
    update();
    
}
    


function update(){
        if(localStorage.getItem('Rohit Pandey') == null){
            Rohit=[];
            localStorage.setItem('Rohit Pandey',JSON.stringify(Rohit));
            }
        else{
           Rohitstr = localStorage.getItem('Rohit Pandey');
           Rohit = JSON.parse(Rohitstr); 
        }

    

     // Populate Table

     let tablebody=document.getElementById("tablebody");
     str="";
     Rohit.forEach((element,index) => {
         str +=` <tr>
                 <td>${index + 1}</td>
                 <td>${element[0]}</td>
                 <td>${element[1]}</td>
                 <td><button class="adde" id="add2" onclick="del(${index})" >Delete</button></td>
                </tr>`;
    });
    tablebody.innerHTML=str;

 
}


addin = document.getElementById("add");
addin.addEventListener("click" , getAnupdate);
update();

//Clearing List
function clearstorage(){
    if(confirm("Do you really want to clear the entire list?")){
    console.log("clearing List...");
    localStorage.clear();
    update();  
    } 
}

//Deleteing
function del(item){
    Rohitstr = localStorage.getItem('Rohit Pandey');
    Rohit = JSON.parse(Rohitstr); 
    Rohit.splice(item, 1);
    localStorage.setItem('Rohit Pandey',JSON.stringify(Rohit));
    update();
}











 