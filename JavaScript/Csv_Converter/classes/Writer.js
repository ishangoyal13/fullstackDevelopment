const fs = require("fs");
const util = require("util");

class Writer {

    constructor() {
        this.writer = util.promisify(fs.writeFile);
    }

    async write(filename, data) {
        try {
            await this.writer(filename,data);
            return true;
        } catch (error) {
            return;
        }
    }
}

module.exports = Writer;