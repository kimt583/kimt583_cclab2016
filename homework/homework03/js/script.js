$(document).ready(function () { 
  

  // This function gets the data from the YouTube API and displays it on the page
  function getResults(searchTerm) {
    $.getJSON("https://www.googleapis.com/youtube/v3/search",
      {
        "part": "snippet",
        "key": "AIzaSyBkK8PEuhSfyz05gnUWhwOuE5cqWV5Oa3A",
        "q": searchTerm,
        "maxResults": 1
      },
      function (data) {
        if (data.pageInfo.totalResults == 0) {
          alert("No results!");
        }
        // If no results, empty the list
        displayResults(data.items);
      }
    );
  }

  //Display results in ul
  function displayResults(videos) {
    var html = "";
    $.each(videos, function (index, video) {
      // Append results li to ul
      console.log(video.snippet.title);
      console.log(video.snippet.thumbnails.high.url);
      html = html + "<li><p class='line-clamp'>" + video.snippet.title +
        "</p><a target='_blank' href='https://www.youtube.com/watch?v=" + video.id.videoId + "'><img src='" +  video.snippet.thumbnails.high.url + "'/></a></li>" ;
    });
    $("#search-results ul").html(html);
  }

  //Use search term
  $("#search-form").submit(function (event) {
    event.preventDefault();
    getResults($("#search-term").val());
  });
});


//This code loads the IFrame Player API code asynchronously.
var tag = document.createElement('script');

    tag.src = "https://www.youtube.com/iframe_api";
    var firstScriptTag = document.getElementsByTagName('script')[0];
    firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

// This function creates an <iframe> (and YouTube player)
// after the API code downloads.
var player;
function onYouTubeIframeAPIReady() {
    player = new YT.Player('player', {
        height: '390',
        width: '100%',
        videoId: 'video.id.videoId',
        playerVars: { 
            'autoplay': 0, 
            'controls': 1,
            'showinfo': 0
        },

    });
}