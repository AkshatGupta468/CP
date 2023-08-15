// In other environments:
const cheerio = require("cheerio")
const axios = require("axios")
const url = "https://codeforces.com/contest/1674/status"
axios.get(url).then((res) => {
  // console.log(res.data);
  const $ = cheerio.load(res.data)
  console.log($(".status-frame-datatable"))
})
