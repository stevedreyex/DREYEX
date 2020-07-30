var isTry=false;    //決定是否為練習模式


var MyMenu = Framework.exClass(Framework.GameMainMenu , {
    //初始化loadingProgress需要用到的圖片
    initializeProgressResource: function() {
        this.loading = new Framework.Sprite(define.imagePath + 'loading.jpg');
        this.loading.position = {x: Framework.Game.getCanvasWidth() / 2 , y: Framework.Game.getCanvasHeight() / 2};

        //為了或得到this.loading這個Sprite的絕對位置, 故需要先計算一次(在Game Loop執行時, 則會自動計算, 但因為loadingProgress只支援draw故需要自行計算)                  
    },

    //在initialize時會觸發的事件
    loadingProgress: function(ctx, requestInfo) {
        //console.log(Framework.ResourceManager.getFinishedRequestPercent())
        this.loading.draw(ctx);
        ctx.font ='90px Arial';
        ctx.textAlign = 'center';
        ctx.fillStyle = 'white';
        ctx.fillText(Math.round(requestInfo.percent) + '%' , ctx.canvas.width / 2 , ctx.canvas.height / 2 + 300);
    },

    load: function(){   


        ////////Load開始標語/////////
        this.startpic = new StartSign();
        this.startpic.load(Framework.Game.getCanvasWidth() / 2 , Framework.Game.getCanvasHeight() / 2);
        this.rootScene.attach(this.startpic.startPic);

        ////////Load選關按鈕/////////
        this.select=new SelectSign();
        this.select.load();
        this.rootScene.attach(this.select.bottonPic);

        ////////Load選關按鈕/////////
        this.confling=new ConflingSign();
        this.confling.load();
        this.rootScene.attach(this.confling.bottonPic);

        ////////Load模板/////////
        this.board=new Board();
        this.board.load();
        this.rootScene.attach(this.board.boardPic);
        this.rootScene.attach(this.board.mBotton.bottonPic);
        



    },
    
    initialize: function() {
        
    },

    update:function(){     
        

        this.board.update(this.select,this.confling);

        
    },

    draw: function(parentCtx) { 
        //this.rootScene.draw();一定要在第一行
        this.rootScene.draw(parentCtx);
        this.board.draw(parentCtx);

    },

    mouseup: function(e) {

    },

    mousedown: function(e) {
        
    },

    click:function(e){      
		//console.log為Browser提供的function, 可以在debugger的console內看到被印出的訊息                    
        if (e) {
            console.log(e.x, e.y);
        }
        /*
        this.previousTouch = { x: e.x, y: e.y };
        if (this.previousTouch.x >= this.startpic.startPic.upperLeft.x && this.previousTouch.x <= this.startpic.startPic.upperRight.x && this.previousTouch.y >= this.startpic.startPic.upperLeft.y && this.previousTouch.y <= this.startpic.startPic.lowerLeft.y) {
            Framework.Game.goToNextLevel();
        }*/
        this.startpic.mousedown(e);
		
        if(!this.confling.isCall){
            this.select.click(e);
        }
        if(!this.select.isCall){
            this.confling.click(e);
        }
        
        this.board.mBotton.click(e);

        isTry=!this.board.mBotton.isClicked;  //讓按鈕控制遊戲模式

        if(this.select.isCall){
            if(this.board.botton[0].click(e)){
                Framework.Game.goToLevel("level1");
            }
            else if(this.board.botton[1].click(e)){
                Framework.Game.goToLevel("level2");
            }
            else if(this.board.botton[2].click(e)){
                Framework.Game.goToLevel("level3");
            }
            else if(this.board.botton[3].click(e)){
                Framework.Game.goToLevel("level4");
            }
            else if(this.board.botton[4].click(e)){
                Framework.Game.goToLevel("level5");
            }
            else if(this.board.botton[5].click(e)){
                Framework.Game.goToLevel("levelR");
            }
        }

        

    },

    mousemove: function(e) {        
		console.log(e.x+", "+e.y);
    },

    mouseup: function(e) {

    },

    touchstart: function (e) {
        //為了要讓Mouse和Touch都有一樣的事件
        //又要減少Duplicated code, 故在Touch事件被觸發時, 去Trigger Mouse事件
        this.mousedown({ x: e.touches[0].clientX, y: e.touches[0].clientY });
    },

    touchend: function (e) {

    },
    
    touchmove: function (e) {

    }
});