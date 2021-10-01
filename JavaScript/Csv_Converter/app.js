const Reader = require("./classes/Reader");
const Processor = require("./classes/Processor");
const Table = require("./classes/Table");
const HtmlParser = require ("./classes/HtmlParser");
const Writer = require("./classes/Writer");
const PDFWriter = require("./classes/PDFWriter");

const reader = new Reader();
const writer = new Writer();


async function main() {
    const data = await reader.read("./test.csv");
    const processedData = Processor.process(data);
    const table = new Table(processedData);
    const html = await HtmlParser.parse(table);
    writer.write(Date.now() + ".html", html); // to HTML
    PDFWriter.writePdf(Date.now() + ".pdf", html); // to PDF
    
}

main();