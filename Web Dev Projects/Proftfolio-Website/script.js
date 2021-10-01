/*-----------------------------Toggler  Navbar-------------------------- */


const navToggler = document.querySelector('.nav-toggler');
navToggler.addEventListener("click",()=>{
  
    hideSection();
    toggleNavbar();
    document.body.classList.toggle("hide-scrolling");
    
});
function toggleNavbar()
{
  document.querySelector(".header").classList.toggle("active");
} 

function hideSection()
{
  document.querySelector("section.active").classList.toggle("fade-out");
}

/*----------------Active Section--------------------*/
document.addEventListener("click",(e)=>{
  if(e.target.classList.contains("link-item") && e.target.hash !== "")
  {
    const hash = e.target.hash;
    navToggler.classList.add("hide");
    if(e.target.classList.contains("nav-item"))
    {
        toggleNavbar();
    }
    else
    {
      hideSection();
      document.body.classList.add("hide-scrolling");
    }
    setTimeout(()=>{
      document.querySelector("section.active").classList.remove("active","fade-out");
      document.querySelector(e.target.hash).classList.add("active");
      window.scrollTo(0,0);
      document.body.classList.remove("hide-scrolling");
      navToggler.classList.remove("hide");
    },500)
  }
})
/*---------------About files------------------------*/

/*-------------------JavaScript for About Tabs------------------*/
const tabsContainer = document.querySelector(".about-tabs");
aboutSection = document.querySelector(".about-section");
tabsContainer.addEventListener("click", (e) => {
  if (
    e.target.classList.contains("tab-item") &&
    !e.target.classList.contains("active")
  ) 
  {
    tabsContainer.querySelector(".active").classList.remove("active");
    e.target.classList.add("active");
    const target = e.target.getAttribute("data-target");
    aboutSection.querySelector(".tab-content.active").classList.remove("active");
    aboutSection.querySelector(target).classList.add("active");
  }
});




/*-----------------Portfolio Items Details Popup Start--------------------*/

document.addEventListener("click",(e)=>{
  if(e.target.classList.contains("view-project-btn"))
  {
    togglePortfolioPopup();
    document.querySelector(".portfolio-popup").scrollTo(0,0);
    portfolioItemDetails(e.target.parentElement);
  }
});

function togglePortfolioPopup(){
  document.querySelector(".portfolio-popup").classList.toggle("open");
  document.body.classList.toggle("hide-scrolling");
  document.querySelector(".main").classList.toggle("fade-out");
}


/* ---------popup when clicked outside of the box ---------*/
document.addEventListener("click",(e)=>{
  if(e.target.classList.contains("pp-inner")){
    togglePortfolioPopup();
  }
})








/* ----------------------For taking details and  images-------------------*/

document.querySelector('.pp-close').addEventListener("click", togglePortfolioPopup)

function portfolioItemDetails(portfolioItem)
{
  document.querySelector(".pp-thumbnail img").src =
  portfolioItem.querySelector(".portfolio-item-thumbnail img").src;

  document.querySelector(".pp-header h3").innerHTML = portfolioItem.querySelector(".portfolio-item-title").innerHTML;

  document.querySelector(".pp-body").innerHTML = portfolioItem.querySelector(".portfolio-item-details").innerHTML;
}

/* ------------------------------- Toggle Navbar-------------------------*/

/* ------------------------------- Toggle Navbar-------------------------*/

















// this way we could  also do it exception
/*-----------------------Closing (X)------------------------------ */
// document.addEventListener("click",(e)=>{
//   if(e.target.classList.contains("pp-close"))
//   {
//     togglePortfolioPopupclose();
//   }
// });

// function togglePortfolioPopupclose(){
//   document.querySelector(".portfolio-popup").classList.remove("open");
//   document.body.classList.remove("hide-scrolling");
//   document.querySelector(".main").classList.remove("fade-out");
// }

/*-----------------Portfolio Items Details Popup End----------------------*/
