// Given a date in the form of "DD/MM/YYYY". Calculate the number of days between the given date and today's date.

function getNumberOfDays(date) {
  let todayDate = new Date();

  let dateArray = date.split("/");
  let dd = parseInt(dateArray[0]);
  let mm = parseInt(dateArray[1]);
  let yy = parseInt(dateArray[2]);

  let dateObject = new Date(yy, mm - 1, dd);

  let milliSecDiff = todayDate.getTime() - dateObject.getTime();
  let daysPassed = Math.floor(milliSecDiff / 86400000);
  return daysPassed;
}
