const axios = require('axios');

axios.all([
    axios.get(`https://apicovid19indonesia-v2.vercel.app/api/indonesia`),
    axios.get(`https://apicovid19indonesia-v2.vercel.app/api/indonesia/provinsi`)
  ])
    .then(axios.spread((covidid, covidprov) => { 
    console.log('DATA INDONESIA')
    console.log(`POSITIF : ${covidid.data.positif} | SEMBUH : ${covidid.data.sembuh} | MENINGGAL : ${covidid.data.meninggal}`)
    console.log('DATA PROVINSI INDONESIA')
    let provinsi = ""
    for(i = 0; i <= 32; i++) {
        console.log(`${covidprov.data[i].provinsi}`)
        console.log(`Positif: ${covidprov.data[i].kasus} Sembuh: ${covidprov.data[i].sembuh} Meninggal: ${covidprov.data[i].meninggal}\n`)
    }
}))
    .catch((err) => {
        console.log("Something error")
})
