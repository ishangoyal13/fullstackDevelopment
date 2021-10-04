async function backstretch(asset) {
  const checkBackstretchFile = astr => {
    const xhr = new XMLHttpRequest()
    return new Promise((resolve, reject) => {
      xhr.onreadystatechange = (e) => {
        if (xhr.readyState !== 4) {
          return
        }
        if (xhr.status === 200) {
          resolve(true)
        } else {
          resolve(false)
        }
      }
      xhr.open('GET', astr)
      xhr.send()
    })
  }
  const createStretch = image => {
    const style = styleString()
    return `
      <div style="${style.wrapper}">
        <img style="${style.image}" src="${image}" />
      </div>
    `
  }
  const styleString = () => {
    const styles = {
      wrapper: {
        "left": "0",
        "top": "0",
        "overflow": "hidden",
        "margin": "0",
        "padding": "0",
        "height": "100vh",
        "width": "100%",
        "z-index": "-999999",
        "position": "fixed"
      },
      image: {
        "position": "absolute",
        "margin": "0",
        "padding": "0",
        "border": "none",
        "width": "100%",
        "height": "100vh",
        "max-width": "none",
        "z-index": "-999999",
        "left": "0",
        "top": "0",
        "object-fit": "cover"
      }
    }
    let strStyle = {
      wrapper: '',
      image: ''
    }
    for (let key in styles.wrapper) { strStyle.wrapper += key + ":" + styles.wrapper[key] + ";" }
    for (let key in styles.image) { strStyle.image += key + ": " + styles.image[key] + "; " }
    return strStyle
  }
  const body = document.querySelector('body')
  const checkImage = await checkBackstretchFile(asset)
  if (!body) return console.error("I didn't find any element body, please check your element 😘")
  if (!asset) return console.error("I didn't find the asset you applied, ensure asset applied from root directory 😉")
  if (!checkImage) return console.error("asset not found 🥺")
  return body.innerHTML += createStretch(asset)
}
