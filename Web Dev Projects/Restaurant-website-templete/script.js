window.addEventListener("load",()=>{
/*------------------------Page Loader---------------------------*/
document.querySelector(".pageloader").classList.add("fade-out");
setTimeout(function(){
    document.querySelector(".pageloader").style.display="none";
},600)
/*--------------------animation on  scroll---------------------*/
  AOS.init();
});






/*--------------------Toggle--NavBar--Start---------------------*/
const navToggler = document.querySelector(".nav-toggler");
navToggler.addEventListener("click",()=>{
    toggleNav();
    blackback();
})

function toggleNav()
{
    navToggler.classList.toggle("active");
    document.querySelector(".nav").classList.toggle("open");
}

function blackback()
{
    document.querySelector(".home-section").classList.toggle("active-black");
    console.log("background  is  black");
}
/*--------------------Toggle--NavBar--End-----------------------*/

/*-------------------Closing of navbar after clicking on option in navbar--start-------------*/
document.addEventListener("click",(e)=>{
    if(e.target.closest(".nav-item"))
    {
        toggleNav();
    }
})
/*-------------------Closing of navbar after clicking on option in navbar--end--------------*/

/*------------------------------Document--Sticky--Header--start---------------------------- */
window.addEventListener("scroll",()=>{
    if(this.pageYOffset > 60)
    {
        document.querySelector(".header").classList.add("sticky");
    }
    else
    {
        document.querySelector(".header").classList.remove("sticky");
    }
})
/*------------------------------Document--Sticky--Header--end------------------------------ */

/*----------------------------Menu Tabs Start---------------------------- */
const menuTabs = document.querySelector(".menu-tabs");
menuTabs.addEventListener("click",(e)=>{
    if(e.target.classList.contains("menu-tab-item") && !e.target.classList.contains("active"))
    {
        const target = e.target.getAttribute("data-target");
        menuTabs.querySelector(".active").classList.remove("active");
        e.target.classList.add("active");
        const menuSection = document.querySelector(".menu-section");
        menuSection.querySelector(".menu-tab-content.active").classList.remove("active");
        
        menuSection.querySelector(target).classList.add("active");

    
            /*--------------------animation on  scroll---------------------*/
              AOS.init();
          
    }
})
/*----------------------------Menu Tabs Ends ---------------------------- */