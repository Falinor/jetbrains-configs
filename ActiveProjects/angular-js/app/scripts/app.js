(function() {

  var app = angular.module('flamestats', [ ]);
 
  app.controller('ViewController', ['$http', function($http) {
    var store = this;
    store.data = [];
    var url = 'https://euw.api.pvp.net/api/lol/euw/v1.2/champion?api_key=100d39bc-4e17-4c36-912b-66f43f9869ec';

    $http.get(url).success(function(data) {
       store.data = data.champions;
    }).error(function(code) {
      
    });

  }]);

})();
