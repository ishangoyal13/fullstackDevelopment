
var completetaskholder=document.getElementById('completed-tasks');
function newtask(){
    var inputValue = document.getElementById("task").value;
    var li = document.createElement("li");
    var t = document.createTextNode(inputValue);
  li.appendChild(t);
    if (inputValue === '') {
      alert("You must write something!");
      return;
    } else {
    console.log(inputValue);
    }
    document.getElementById("task").value = "";
    
    
    var checkBox=document.createElement("input")
    checkBox.type="checkbox";
    checkBox.classList='checked';
    checkBox.onclick= completeItem;
    li.appendChild(checkBox);
  var prtask=document.getElementById('myUL')
  prtask.append(li);
  li.onclick = removeItem; 

}
function removeItem(e) {
    e.target.remove();
  }


  function completeItem(e){
    var listItem=this.parentNode;
completetaskholder.appendChild(listItem);
console.log(completetaskholder)
  }