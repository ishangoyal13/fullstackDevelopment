const fs = require("fs");
const util = require("util");

class Reader {

    constructor() {
        this.fileReader = util.promisify(fs.readFile);
    }

    async read(filepath) {
        try {
            return await this.fileReader(filepath, "utf8");
        } catch (error) {
            return;
        }
    }
}

module.exports = Reader;