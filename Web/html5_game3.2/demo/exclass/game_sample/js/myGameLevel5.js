var MyGame5 = Framework.Class(Framework.Level , {
	load: function(){
      

        this.setX=200;
        this.setY=200;


        this.isEnd=false;
        this.isOut=false;


        ////////Load倒數計時器/////////
        this.timer=new Timer();
        this.timer.load();
        for(i=0;i<10;i++){
            this.rootScene.attach(this.timer.digitPic1[i]);
            this.rootScene.attach(this.timer.digitPic2[i]);
        }

        
        this.gameTunnel=[];
        

        ////////Load通道/////////
        this.gameTunnel[0]=new GameGTunnel(11); //參數為通道長度*60
        this.gameTunnel[0].load(200,200,10);
        this.rootScene.attach(this.gameTunnel[0]);

        ////////Load通道2/////////
        this.gameTunnel[1]=new GameGTunnel(2); //參數為通道長度*60
        this.gameTunnel[1].load(836,308,0);
        this.rootScene.attach(this.gameTunnel[1]);

        ////////Load通道3/////////
        this.gameTunnel[2]=new RotTunnel(0.5); //參數為旋轉速度
        this.gameTunnel[2].load(926,308,0);
        this.rootScene.attach(this.gameTunnel[2].tunnelPic);
        this.gameTunnel[2].get_stopP(0);    //設定頓點
        this.gameTunnel[2].get_stopP(180);

        ////////Load通道4/////////
        this.gameTunnel[3]=new GameGTunnel(10); //參數為通道長度*60
        this.gameTunnel[3].load(1250,308,0);
        this.rootScene.attach(this.gameTunnel[3]);

        ////////Load終點/////////
        this.goalpic = new GoalSign();
        this.goalpic.load(Framework.Game.getCanvasWidth()-52,308);
        this.rootScene.attach(this.goalpic.goalPic);


        ////////Load開始標語/////////
        this.startpic = new StartSign();
        this.startpic.load(this.setX,this.setY);
        this.rootScene.attach(this.startpic.startPic);

        
        ////////Load滑鼠圖形隨行/////////
        this.mousepic = new MousePicMove();
        this.mousepic.load(this.setX,this.setY);
        this.rootScene.attach(this.mousepic.mousePic);

        ////////Load過關畫面，但先不貼出圖/////////
        this.endScene=new EndScene();
        this.endScene.load();
        this.rootScene.attach(this.endScene.clearPic);


        ////////Load死亡畫面，但先不貼出圖/////////
        this.overScene=new OverScene();
        this.overScene.load();
        this.rootScene.attach(this.overScene.clearPic);



        //載入要被播放的音樂清單
        //資料夾內只提供mp3檔案, 其餘的音樂檔案, 請自行轉檔測試
        this.audio = new Framework.Audio({
            kick: {
                mp3: define.musicPath + 'kick2.mp3',
                //ogg: define.musicPath + 'kick2.ogg',
                //wav: define.musicPath + 'kick2.wav'
            }, song1:{
                mp3: define.musicPath + 'easy.mp3',
                //ogg: define.musicPath + 'Hot_Heat.ogg',
                //wav: define.musicPath + 'Hot_Heat.wav'
            }
        });

        //播放時, 需要給name, 其餘參數可參考W3C
        this.audio.play({name: 'song1', loop: true});

	},

    initialize: function() {
        this.mousepic.initialize();
        this.endScene.initialize();
        this.overScene.initialize();
        this.startpic.initialize();
        this.timer.initialize();

        this.isEnd=false;    //告知關卡終結的布林代數要重設回false
        this.isOut=false;

    },



    update: function() {
        var game = this;
        this.rootScene.update(); 

        this.mousepic.update();    //滑鼠游標


        if(this.mousepic.isStart){
            this.timer.update();  //倒數計時器
        }
        
        if(!this.goalpic.isClear && !this.isEnd){
            this.gameTunnel[2].update();     //可旋轉通道
        }

        this.covered(this.mousepic);    //將所有通道統合並確認是否在通道內





        if(this.isOut ) {    //如果超出通道就撥放音樂
            this.audio.play({name: 'kick'});
            if(!isTry){                     //看是否為練習模式
                this.mousepic.isStart=false;
                this.overScene.update();
            }
            
        }
        
        if(this.timer.dd==0 &&this.timer.d1==0){    //看時間是否為00
            this.mousepic.isStart=false;
            if(!isTry){                     //看是否為練習模式
                this.isOut=true;
                this.overScene.update();
            }
        }


        if(this.mousepic.isStart&&this.goalpic.isClear){    
            this.isEnd=true;
            this.mousepic.isStart=false;
        }

        if(this.isEnd){
            this.endScene.update();
        }

       
    },


    covered:function(target){
        for(i=0;i<360;i=i+3){
            this.surround_position={             //運算出圖形周邊各點的位置
                x:target.position.x+15*Math.cos(i*Math.PI/180),
                y:target.position.y+15*Math.sin(i*Math.PI/180)
            };

            //this.isOut=!(this.gameTunnel[0].covered(this.surround_position.x,this.surround_position.y) || this.gameTunnel[1].covered(this.surround_position.x,this.surround_position.y));

            for(j=0;j<4;j++){          //利用j迴圈做or運算
                this.isOut=!(this.gameTunnel[j].covered(this.surround_position.x,this.surround_position.y) );
                if(!this.isOut){
                    break;
                }                
            }

            if(this.isOut){  //如果任何一點不在通道內就跳出i迴圈
                break;
            }



        }

    },

    draw:function(parentCtx){
       // this.rootScene.draw();

        /////////以下為原遊戲的CLICK ME按鈕/////////
        //可支援畫各種單純的圖形和字
        //parentCtx.fillStyle = (this.secondHandRotationRate > 0)?'green':'red'; 
        //parentCtx.fillRect(this.rectPosition.x , this.rectPosition.y, 260, 90);  
        //parentCtx.font = '65pt bold';
        //parentCtx.fillStyle = 'white';
        //parentCtx.textBaseline = 'top';
        //parentCtx.textAlign = 'center';
        //parentCtx.fillText('Click Me to Start', this.rectPosition.x + 130, this.rectPosition.y, 260);
        /////////以上為原遊戲的CLICK ME按鈕/////////
        if(this.isEnd){
            this.endScene.draw(parentCtx);
        }

        if(this.isOut && !isTry){
            this.overScene.draw(parentCtx);
        }

    },



    keydown:function(e, list){
        Framework.DebugInfo.Log.warning(e.key);

        if(e.key === 'Enter') {
            if(!this.isFullScreen) {
                Framework.Game.fullScreen();
                this.isFullScreen = true;
            } else {
                Framework.Game.exitFullScreen();
                this.isFullScreen = false;
            }
            
        }
        if(e.key === 'A') {
            if(!isTry) {
                isTry = true;
            } else {
                isTry = false;
            }
            
        }
    },

    touchstart: function (e) {
        //為了要讓Mouse和Touch都有一樣的事件
        //又要減少Duplicated code, 故在Touch事件被觸發時, 去Trigger Mouse事件
        this.click({ x: e.touches[0].clientX, y: e.touches[0].clientY });
    },

    mousemove: function(e) {        //偵測滑鼠移動並播放圖片
        this.mousepic.mousemove(e);
        this.goalpic.mousemove(e);
    },

    mousedown:function(e){
        this.mousepic.mousedown(e);
        if(this.mousepic.isStart){
            this.startpic.go_out();  //如果開始遊戲就讓起始標示丟到畫面外
        }

        if(this.endScene.btn1_clicked(e) && this.isEnd){    //以下為如果破關的按鈕
            Framework.Game.goToNextLevel();
        }

        if(this.endScene.btn2_clicked(e) && this.isEnd){
            this.initialize();
        }



        if(this.overScene.btn1_clicked(e) && this.isOut && !isTry){   //以下為如果失敗的按鈕
            Framework.Game.goToLevel("menu");
        }

        if(this.overScene.btn2_clicked(e) && this.isOut){
            this.initialize();
        }


    },
    
    click: function (e) {  
        
        console.log(e.x, e.y);

    },
});