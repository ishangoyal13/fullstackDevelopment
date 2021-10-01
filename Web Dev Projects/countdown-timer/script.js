const dayname = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];

const monthname = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

const title = document.querySelector(".title h3");
const smallBox = document.querySelectorAll(".small-box h3");

const date = new Date(2021, 10, 31, 23, 59, 59);

const dateNumber = date.getDate();
const month = monthname[date.getMonth()];
const year = date.getFullYear();
const day = dayname[date.getDay()];

title.textContent = `Hacktoberfest will be ended on ${day}, ${dateNumber} ${month} ${year}`;

const deadline = date.getTime();

const time = () => {
  let t = deadline - new Date().getTime();

  let oneDay = 24 * 60 * 60 * 1000;
  let oneHour = 60 * 60 * 1000;
  let oneMinute = 60 * 1000;
  let oneSecond = 1000;

  let day = Math.floor(t / oneDay);
  let hour = Math.floor((t % oneDay) / oneHour);
  let minute = Math.floor((t % oneHour) / oneMinute);
  let second = Math.floor((t % oneMinute) / oneSecond);

  const format = (hours) => {
    if (hours < 10) {
      hours = `0${hours}`;
    }
    return hours;
  };

  const values = [day, hour, minute, second];

  smallBox.forEach((item, index) => {
    item.innerHTML = format(values[index]);
  });

  if (t < 0) {
    clearInterval(countdown);
    smallBox.forEach((item) => {
      item.innerHTML = "00";
    });
    title.textContent = "Hacktoberfest has ended!";
  }
};

const countdown = setInterval(time, 1000);

time();
