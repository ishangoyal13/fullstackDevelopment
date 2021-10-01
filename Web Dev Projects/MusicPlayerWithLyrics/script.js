console.clear();
var _data = JSON.parse(`{
    "lyrics":[
    
    {"line":"","time":-1},
    
    {"line":"Unmei nante ienai","time":2780},
    
    {"line":"Ato nansenchi chika zukeba iindarou","time":5800},
    
    {"line":"Kimi ga (Kimi ga) iito","time":9900},
    
    {"line":"Ienai mama mitsumeteru ushiro sugata","time":12400},

    {"line":"Yoyuu no nai hibi desu","time":23750},

    {"line":"Deeto nante Jishin ga naina","time":27350},

    {"line":"Kimi ga mabushii hodo","time":30830},

    {"line":"Boku wa nasake nakunatteku","time":33770},

    {"line":"Aenai jikan purasu kimi ga waratta shuunkan","time":37050},

    {"line":"Waru ni no kono Tokimeki to","time":40710},

    {"line":"Bukiyou na boku,","time":44130},

    {"line":"Dakedo Tsuyogari na kimi wa","time":46170},

    {"line":"Angai Purasu kamotte","time":47570},

    {"line":"Kizuite shimattara Saigo","time":51090},

    {"line":"Mada ne Unmei Nante ienai","time":55000},

    {"line":"Ato nansenchi chikazukeba iindarou","time":58960},

    {"line":"Boku wa (boku wa) kimi ni","time":62400},

    {"line":"Nani wo shite agereru kana","time":65800},

    {"line":"Ano hi daijoubu tte egao","time":69000},

    {"line":"Ato nansenchi saki wo arui tendarou","time":72500},

    {"line":"Kimiga (kimiga) iito","time":76500},

    {"line":"Ieba oi tsukeru nokana","time":79500},

    {"line":"Todoku nokana","time":82000},

    {"line":"........","time":84000},

    {"line":"Futo shita shunkan ni","time":90600},

    {"line":"Kimi no samishisa wo shittan da","time":93800},

    {"line":"Yowai boku wa hora ne","time":96990},

    {"line":"Hanarerarenaku natteku","time":100090},

    {"line":"yatto kita chansu purasu itadakenai kono kaiwa","time":103700},

    {"line":"waru ni de munashiku tatte","time":107500},

    {"line":"Futashika na kyou","time":110500},

    {"line":"kakeru fuantei na kanjou dakara koso boku wa kimi wo","time":112900},

    {"line":"Mitsukerareta no kamo shirenai","time":117500},

    {"line":"Dakara unmei datte shinjitai","time":122500},

    {"line":"Ima suu senchi chikazuitemo ii ka na","time":125600},

    {"line":"Mune wo saku yo furimuite kureru tabi ni","time":129600},

    {"line":"Kimi no egao mo kotoba mo","time":135700},

    {"line":"Mou nan senchi tsumotte kie ya shinai","time":139500},

    {"line":"Kireigoto ja katazukerarenai hodo ni omotteiru","time":143400},

    {"line":".....","time":151100},

    {"line":"Unmei da tte ieru made","time":165300},

    {"line":"Waratta you ni miseta kimi ni todoku made","time":168800},

    {"line":"Tokubetsu janai ima no boku ni dekiru koto","time":172800},

    {"line":"Mada ne unmei nante ienai","time":179000},

    {"line":"Ato nan senchi chikazukeba iin darou","time":182000},

    {"line":"Boku wa sukoshi kawatte yukeru ki ga suru","time":186400},

    {"line":"Tadoritsuita toki wa kimi ni","time":192800},

    {"line":"Daijoubu da yo boku ga saki ni iu kara","time":196000},

    {"line":"Kimi ga (kimi ga) suki da","time":199999},

    {"line":"owaranai kono omoi ga","time":202700},

    {"line":"todokimasu you ni","time":205500},

    {"line":".....","time":208400},

    {"line":"Thanks For Visit","time":220000},

    {"line":".....","time":250000}
    
    ]}`);
var currentLine = "";

function align() {
    var a = $(".highlighted").height();
    var c = $(".content").height();
    var d = $(".highlighted").offset().top - $(".highlighted").parent().offset().top;
    var e = d + (a / 2) - (c / 2);
    $(".content").animate({ scrollTop: e + "px" }, { easing: "swing", duration: 250 });
}

var lyricHeight = $(".lyrics").height();
$(window).on("resize", function() {
    if ($(".lyrics").height() != lyricHeight) { //Either width changes so that a line may take up or use less vertical space or the window height changes, 2 in 1
        lyricHeight = $(".lyrics").height();
        align();
    }
});

$(document).ready(function() {
    $("video").on('timeupdate', function(e) {
        var time = this.currentTime * 1000;
        var past = _data["lyrics"].filter(function(item) {
            return item.time < time;
        });
        if (_data["lyrics"][past.length] != currentLine) {
            currentLine = _data["lyrics"][past.length];
            $(".lyrics div").removeClass("highlighted");
            $(`.lyrics div:nth-child(${past.length})`).addClass("highlighted"); //Text might take up more lines, do before realigning
            align();
        }
    });
});

generate();

function generate() {
    var html = "";
    for (var i = 0; i < _data["lyrics"].length; i++) {
        html += "<div";
        if (i == 0) {
            html += ` class="highlighted"`;
            currentLine = 0;
        }
        if (_data["lyrics"][i]["note"]) {
            html += ` note="${_data["lyrics"][i]["note"]}"`;
        }
        html += ">";
        html += _data["lyrics"][i]["line"] == "" ? "•" : _data["lyrics"][i]["line"];
        html += "</div>"
    }
    $(".lyrics").html(html);
    align();
}