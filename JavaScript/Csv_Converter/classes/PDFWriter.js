const pdf = require("html-pdf");

class PDFWriter {
    static writePdf(filename, html) {
        pdf.create(html, {}).toFile(filename, error => {
            console.log(error);
        });
    }
}

module.exports = PDFWriter;