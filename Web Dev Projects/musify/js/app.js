let fillbar = document.querySelector(".fill")
let audios=["Audio_One.mp3","Audio_Two.mp3","Audio_Three.mp3"];
let covers = ["cover1.jpg","cover2.jpg","cover3.jpg"];
let songNames = ["Ride", "Into The Night", "Bang Bang"];
let singers = ["Twenty One Pilots", "Prateek Kuhad", "Snoop Dogg"]
let currentTime=document.querySelector(".time")

//create an object of Audio
let audio = new Audio()
let currentSong = 0
let currentSongName = 0
let currentSingerName = 0

//whenever the window load, song should play automatically
window.onload = playSong

//lets play the song by this function whenever window load

function playSong(){
    audio.src = audios[currentSong]
    //audio.play()
}




//Play Pause impppppp
function togglePlayPause(){
    if(audio.paused){
        audio.play()
        let playBtn = document.querySelector(".play-pause")
        playBtn.innerHTML = '<i class = "fa fa-pause"></i>'
        playBtn.style.paddingLeft="30px"
    }else{
        audio.pause()
        let playBtn = document.querySelector(".play-pause")
        playBtn.innerHTML = '<i class = "fa fa-play"></i>'
        playBtn.style.paddingLeft = "33px"
    }
}

// dynamic  fillbar

audio.addEventListener("timeupdate", function() {
    let position = audio.currentTime / audio.duration;
    fillbar.style.width = position * 100 + "%";
  
    // duration
    convertTime(Math.round(audio.currentTime));
  
    //  play next song when current song completed
  
    if (audio.ended) {
      nextAudio();
    }
  });
  
  function convertTime(seconds) {
    let min = Math.floor(seconds / 60);
    let sec = seconds % 60;
    // single digit
    min = min < 10 ? "0" + min : min;
    sec = sec < 10 ? "0" + sec : sec;
    currentTime.textContent = min + ":" + sec;
  
    // total time
    totalTime(Math.round(audio.duration));
  }
  
  function totalTime(seconds) {
    let min = Math.floor(seconds / 60);
    let sec = seconds % 60;
  
    // single digit
  
    min = min < 10 ? "0" + min : min;
    sec = sec < 10 ? "0" + sec : sec;
    currentTime.textContent += " & " + min + ":" + sec;
  }
  
  // next and prev buttons
  
  function nextAudio() {
    currentSong++;
    if (currentSong > 2) {
      currentSong = 0;
    }
    playSong();
    playBtn = document.querySelector(".play-pause");
    playBtn.innerHTML = '<i class="fa fa-pause"></i>';
    playBtn.style.paddingLeft = "30px";
    // just one line jquery for changing the covers
  
    $(".img img").attr("src", covers[currentSong]);
  }

  
  function prevAudio() {
    currentSong--;
    if (currentSong < 0) {
      currentSong = 2;
    }
    playSong();
    playBtn = document.querySelector(".play-pause");
    playBtn.innerHTML = '<i class="fa fa-pause"></i>';
    playBtn.style.paddingLeft = "30px";
    // just one line jquery for changing the covers
  
    $(".img img").attr("src", covers[currentSong]);
  }
  
  // volume up , down and mute
  
  function decreaseVolume() {
    audio.volume -= 0.25;
  }
  
  function increaseVolume() {
    audio.volume += 0.25;
  }
  
  // speaker muted button
  
  let volumeUp = document.querySelector(".volume-up");
  volumeUp.addEventListener("click", function() {
    if (audio.volume === 1) {
      audio.volume = 0;
      document.querySelector(".volume-up i").className = "fa fa-volume-mute";
    } else {
      audio.volume = 1;
      document.querySelector(".volume-up i").className = "fa fa-volume-up";
    }
  });
  