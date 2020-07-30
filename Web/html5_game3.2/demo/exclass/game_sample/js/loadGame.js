//立即執行函式, 並封裝所有變數避免衝突
var loadGameEnd;
(function(){
    //動態依序載入JS
    //ref: http://blog.darkthread.net/blogs/darkthreadtw/archive/2009/01/15/4061.aspx
    var  importJS = function(jsConf, src, lookFor) {
        var headID = document.getElementsByTagName("head")[0]; 
        var newJs = document.createElement('script');
        newJs.type = 'text/javascript';
        newJs.src= jsConf[0].src;
        headID.appendChild(newJs);
        wait_for_script_load(jsConf, function() {
            jsConf.splice(0, 1);
            if(jsConf.length > 0) {
                importJS(jsConf, lookFor);
            }else
			{
				loadGameEnd = true;
			}
        });
    }

    var wait_for_script_load = function(jsConf, callback) {
        var interval = setInterval(function() {
            if (typeof jsConf[0].lookFor === 'undefined') {
                jsConf[0].lookFor = '';
            }

            if (jsConf[0].lookFor === '') {
                clearInterval(interval);
                callback();
            } else if (eval("typeof " + jsConf[0].lookFor) !== 'undefined') {
                    clearInterval(interval);
                    callback();      
                }
            }, 50);
    }

    //陣列和載入JS檔的順序相同, lookFor為在要載入的檔案中, 
    //有用到的全域變數, importJS這個function, 會在找到lookFor的變數後
    //才會繼續loading下一個檔案, 如果沒有需要lookFor, 則以空字串代表
    var listScript = 
    [
        { src: 'game_sample/js/define.js', lookFor: 'define' },
        { src: 'game_sample/js/myMenu.js', lookFor: 'MyMenu' },
        { src: 'game_sample/js/character.js', lookFor: 'Character' },
        { src: 'game_sample/js/Board.js', lookFor: 'Board' },//面板通用型
        { src: 'game_sample/js/Botton.js', lookFor: 'Botton' },//按鈕通用型
        { src: 'game_sample/js/MousePicMove.js', lookFor: 'MousePicMove' },//滑鼠游標圖形
        { src: 'game_sample/js/GameGTunnel.js', lookFor: 'GameGTunnel' },//通道構圖(通用)prot.
        { src: 'game_sample/js/SelectSign.js', lookFor: 'SelectSign' },//選關指示
        { src: 'game_sample/js/ConflingSign.js', lookFor: 'ConflingSign' },//控制指示
        { src: 'game_sample/js/MovingBotton.js', lookFor: 'MovingBotton' },//橫移按鈕
        { src: 'game_sample/js/startSign.js', lookFor: 'StartSign' },//開始指示
        { src: 'game_sample/js/GoalSign.js', lookFor: 'GoalSign' },//終點指示
        { src: 'game_sample/js/EndScene.js', lookFor: 'EndScene' },//破關圖
        { src: 'game_sample/js/OverScene.js', lookFor: 'OverScene' },//死亡圖
        { src: 'game_sample/js/MovingBlock.js', lookFor: 'MovingBlock' },//障礙物
        { src: 'game_sample/js/MovingHBlock.js', lookFor: 'MovingHBlock' },//橫移障礙物
        { src: 'game_sample/js/MovingTunnel.js', lookFor: 'MovingTunnel' },//橫移通道
        { src: 'game_sample/js/MovingPTunnel.js', lookFor: 'MovingPTunnel' },//直移通道
        { src: 'game_sample/js/RotTunnel.js', lookFor: 'RotTunnel' },//旋轉通道
        { src: 'game_sample/js/Map.js', lookFor: 'Map' },//地圖陣列
        { src: 'game_sample/js/Timer.js', lookFor: 'Timer' },//計時器
        { src: 'game_sample/js/myGameLevel1.js', lookFor: 'MyGame' },
        { src: 'game_sample/js/myGameLevel2.js', lookFor: 'MyGame2' },
        { src: 'game_sample/js/myGameLevel3.js', lookFor: 'MyGame3' },
        { src: 'game_sample/js/myGameLevel4.js', lookFor: 'MyGame4' },
        { src: 'game_sample/js/myGameLevel5.js', lookFor: 'MyGame5' },
        { src: 'game_sample/js/myGameLevelR.js', lookFor: 'MyGameR' },
        { src: 'game_sample/js/mainGame.js'}
    ]

    importJS(listScript);
    
})();


    
