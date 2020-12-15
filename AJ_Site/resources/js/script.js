function getTag() {
    return document.getElementById("tag").value;
}

function photoNum() {
    return document.getElementById("photoNum").value;
}


function makeApiCall() {
    let numPhotos = photoNum();
    let filterTag = getTag();
    let url = `https://www.flickr.com/services/rest/?method=flickr.photos.search&api_key=0e2d3ad5daf58dbd24b5a5880063b9df&tags=${filterTag}&privacy_filter=1&safe_search=1&extras=&per_page=${numPhotos}&page=&format=json&nojsoncallback=1`;
    $.ajax({ url: url, dataType: "json" }).then(function (data) {
        console.log(data);
        let s;
        let tit;
        let pID;
        let sID;
        let card = "";
        let n = 0
        while(n < numPhotos) {
            pID = data.photos.photo[n].id;
            sID = data.photos.photo[n].server;
            s = data.photos.photo[n].secret;
            title = data.photos.photo[n].title;

            card+= `<div class="card text-center">
                <img class="card-img-top" src="https://live.staticflickr.com/${sID}/${pID}_${s}.jpg" alt="error">
                    <div class="card-body">
                        <p class="card-text">${tit}</p>
                    </div>
            </div>`
            n = n + 1;
        }
        card = card + "</div>";
        document.getElementById("photogallery").innerHTML = card;
    })
}

function clear() {
    document.getElementById("photogallery").innerHTML = "";
    window.scrollTo(0,0);
}