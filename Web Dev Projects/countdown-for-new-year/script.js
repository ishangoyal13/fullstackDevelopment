const daysElement = document.getElementById('days');
const hoursElement = document.getElementById('hours');
const minsElement = document.getElementById('minutes');
const secondsElement = document.getElementById('seconds');



const newYears = "1 Jan 2022";

function countdown(){
    const newYearsDate = new Date(newYears);
    const currentDate = new Date();

    const totalSeconds = (newYearsDate - currentDate) / 1000;



    const day = Math.floor(totalSeconds / 3600 / 24);
    const hour = Math.floor(totalSeconds/3600) % 24;
    const minute = Math.floor(totalSeconds/60) %60;
    const second = Math.floor(totalSeconds) % 60;

    daysElement.innerHTML = day;
    hoursElement.innerHTML = formatTime(hour);
    minsElement.innerHTML = formatTime(minute);
    secondsElement.innerHTML = formatTime(second);
}

function formatTime(time) {
    return time < 10? `0${time}` : time;
}


countdown();
setInterval(countdown, 1000);