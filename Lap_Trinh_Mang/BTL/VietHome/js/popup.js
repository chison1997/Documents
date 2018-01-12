    if(localStorage.note==null){
localStorage.note='';
}

function loadnote(){
document.getElementById('notedisplay').innerHTML=localStorage.note;
if(localStorage.note.length<4){document.getElementById('notedisplay').innerHTML='<br><br>     <center style="font-size:17px;color:#999">Bạn không có nhắc nhở nào</center>'}
display=document.getElementById('notedisplay');
for (i = 0; i < display.getElementsByClassName('note').length; i++) { 
    display.getElementsByClassName('note')[i].addEventListener('click', function (e) {
    e.target.remove();
    localStorage.note=document.getElementById('notedisplay').innerHTML;
if(localStorage.note.length<4){document.getElementById('notedisplay').innerHTML='<br><br>     <center style="font-size:17px;color:#999">Bạn không có nhắc nhở nào</center>'}
});
}

}
loadnote();
function addnote(){
if(document.getElementById('noteip').value.length>1){
localStorage.note='<div class="note"><i class="fa fa-check" aria-hidden="true"></i> &nbsp;'+document.getElementById('noteip').value+'</div>'+localStorage.note;
document.getElementById('noteip').value=''
loadnote();
}
}

document.querySelector('#noteip').addEventListener('keypress', function (e) {
    var key = e.which || e.keyCode;
    if (key === 13) {
	addnote();
    }
});