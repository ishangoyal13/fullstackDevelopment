

class Table {

    constructor(arr) {
        this.header = arr[0];
        arr.shift();
        this.rows = arr;
    }

    get rowCount() {
        return this.rows.length;
    }

    get columnCount() {
        return this.reader.length;
    }
}

module.exports = Table;