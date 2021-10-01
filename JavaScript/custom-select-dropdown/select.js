export default class Select {
    // custom class for our custom select
    constructor(element) {
        // the elements which will be visible
      this.element = element
      this.options = getFormattedOptions(element.querySelectorAll("option"))
      this.customElement = document.createElement("div")
      this.labelElement = document.createElement("span")
      this.optionsCustomElement = document.createElement("ul")
      setupCustomElement(this)
      element.style.display = "none"
      element.after(this.customElement)
    }
  
    get selectedOption() {
        // get selected option
      return this.options.find(option => option.selected)
    }
  
    get selectedOptionIndex() {
        // get selected option index
      return this.options.indexOf(this.selectedOption)
    }
  
    selectValue(value) {
      // get selected option value
      const newSelectedOption = this.options.find(option => {
        return option.value === value
      })
      // unselect the current selected option
      const prevSelectedOption = this.selectedOption
      prevSelectedOption.selected = false
      prevSelectedOption.element.selected = false
  
      // select the new option
      newSelectedOption.selected = true
      newSelectedOption.element.selected = true
      
      // chnage the label into option value
      this.labelElement.innerText = newSelectedOption.label
      // remove the selected class from the specific option that was selected previously
      this.optionsCustomElement
        .querySelector(`[data-value="${prevSelectedOption.value}"]`)
        .classList.remove("selected")
      const newCustomElement = this.optionsCustomElement.querySelector(
        `[data-value="${newSelectedOption.value}"]`
      )
      newCustomElement.classList.add("selected")
      newCustomElement.scrollIntoView({ block: "nearest" })
    }
  }
  
  function setupCustomElement(select) {
    select.customElement.classList.add("custom-select-container")
    // to make the custom element tab selectable
    select.customElement.tabIndex = 0
  
    select.labelElement.classList.add("custom-select-value")
    select.labelElement.innerText = select.selectedOption.label
    select.customElement.append(select.labelElement)
  
    select.optionsCustomElement.classList.add("custom-select-options")
    select.options.forEach(option => {
      const optionElement = document.createElement("li")
      optionElement.classList.add("custom-select-option")
      optionElement.classList.toggle("selected", option.selected)
      optionElement.innerText = option.label
      optionElement.dataset.value = option.value
      optionElement.addEventListener("click", () => {
        select.selectValue(option.value)
        select.optionsCustomElement.classList.remove("show")
      })
      select.optionsCustomElement.append(optionElement)
    })
    select.customElement.append(select.optionsCustomElement)
  
    select.labelElement.addEventListener("click", () => {
      select.optionsCustomElement.classList.toggle("show")
    })
  
    select.customElement.addEventListener("blur", () => {
      select.optionsCustomElement.classList.remove("show")
    })
  
    // run with time lapse of 500ms
    let debounceTimeout
    let searchTerm = ""
    select.customElement.addEventListener("keydown", e => {
      switch (e.code) {
        case "Space":
          select.optionsCustomElement.classList.toggle("show")
          break
        case "ArrowUp": {
          const prevOption = select.options[select.selectedOptionIndex - 1]
          if (prevOption) {
            select.selectValue(prevOption.value)
          }
          break
        }
        case "ArrowDown": {
          const nextOption = select.options[select.selectedOptionIndex + 1]
          if (nextOption) {
            select.selectValue(nextOption.value)
          }
          break
        }
        case "Enter":
        case "Escape":
          select.optionsCustomElement.classList.remove("show")
          break
        default: {
          // custom search
          clearTimeout(debounceTimeout)
          searchTerm += e.key
          debounceTimeout = setTimeout(() => {
            searchTerm = ""
          }, 500)
  
          const searchedOption = select.options.find(option => {
            return option.label.toLowerCase().startsWith(searchTerm)
          })
          if (searchedOption) {
            select.selectValue(searchedOption.value)
          }
        }
      }
    })
  }
  
  function getFormattedOptions(optionElements) {
    // converting to array to use map
    return [...optionElements].map(optionElement => { 
      return {
        value: optionElement.value,
        label: optionElement.label,
        selected: optionElement.selected,
        element: optionElement,
      }
    })
  }