var MyGameR = Framework.Class(Framework.Level , {
       


    load: function(){
      
        
        this.M=60;
        this.t_n=5;   //通道數量

        this.isEnd=false;
        this.isOut=false;

        this.gameTunnel=[];


        this.map=new Map();


        this.map_x=Math.round((Math.random()*20+3));
        this.map_y=Math.round((Math.random()*10+4));
        this.setX1=this.map_x*60;
        this.setY1=this.map_y*60;


        ////////Load開始標語////////
        this.startpic = new StartSign();
        this.startpic.load(this.setX1,this.setY1);
        




        this.map_x=Math.round((Math.random()*20+3));
        this.map_y=Math.round((Math.random()*10+4));
        this.setX2=this.map_x*60;
        this.setY2=this.map_y*60;
        this.len1=Math.round(Math.sqrt(Math.pow(this.setX1-this.setX2,2)+Math.pow(this.setY1-this.setY2,2))/60);
        this.rot1=360-Math.atan2(this.setY1-this.setY2,-this.setX1+this.setX2)*180/Math.PI;



        ////////////////以下產生隨機的第三點計算新的通道2參數///////////////////

        this.map_x=Math.round((Math.random()*20+3));
        this.map_y=Math.round((Math.random()*10+5));
        this.setX3=this.map_x*60;
        this.setY3=this.map_y*60;
        this.len2=Math.round(Math.sqrt(Math.pow(this.setX2-this.setX3,2)+Math.pow(this.setY2-this.setY3,2))/60);
        this.rot2=360-Math.atan2(this.setY2-this.setY3,-this.setX2+this.setX3)*180/Math.PI;


        this.rot_df=this.rot2-this.rot1;  //計算兩通道間的斜率差 ,如果小於0就補360
        if(this.rot_df<0){
            this.rot_df=this.rot_df+360;
        }

        while(this.rot_df<90 || this.rot_df>270 || (this.rot_df>140&&this.rot_df<220) ||this.len2<5){
            this.map_x=Math.round((Math.random()*20+3));
            this.map_y=Math.round((Math.random()*10+5));
            this.setX3=this.map_x*60;
            this.setY3=this.map_y*60;
            this.len2=Math.round(Math.sqrt(Math.pow(this.setX2-this.setX3,2)+Math.pow(this.setY2-this.setY3,2))/60);
            this.rot2=360-Math.atan2(this.setY2-this.setY3,-this.setX2+this.setX3)*180/Math.PI;


            this.rot_df=this.rot2-this.rot1;  //計算兩通道間的斜率差 ,如果小於0就補360
            if(this.rot_df<0){
                this.rot_df=this.rot_df+360;
            }
        }


        ////////////////以上產生隨機的第三點計算新的通道2參數///////////////////

        

        ////////Load滑鼠圖形隨行/////////
        this.mousepic = new MousePicMove();
        this.mousepic.load(this.setX1,this.setY1);
        

        this.len1=this.map.check(this.setX1,this.setY1,this.len1,this.rot1);    //把通道參數丟進map陣列檢查
        ////////Load通道/////////
        this.gameTunnel[0]=new GameGTunnel(this.len1); //參數為通道長度*60
        this.gameTunnel[0].load(this.setX1,this.setY1,this.rot1);
        this.rootScene.attach(this.gameTunnel[0]);



        this.endPosition={                      //以this.setXY為基準計算通道末端位置
            x:this.setX1+this.M*(this.len1-1/2)*Math.cos(this.rot1*Math.PI/180),
            y:this.setY1+this.M*(this.len1-1/2)*Math.sin(this.rot1*Math.PI/180)
        }

        this.calculate_T12_differ();     //計算通道1與通道2的偏移


        this.len2=this.map.check(this.endPosition.x,this.endPosition.y,this.len2,this.rot2);    //把通道參數丟進map陣列檢查
        ////////Load通道2/////////
        this.gameTunnel[1]=new GameGTunnel(this.len2); 
        this.gameTunnel[1].load(this.endPosition.x,this.endPosition.y,this.rot2);
        this.rootScene.attach(this.gameTunnel[1]);



////////////////////////////以下為移動型通道的通用prot.

        this.setX1=this.endPosition.x;     //將通道2設為新的起始
        this.setY1=this.endPosition.y;
        this.len1=this.len2;
        this.rot1=this.rot2;

        this.endPosition={                      //以this.setXY為基準計算通道末端位置
            x:this.setX1+this.M*(this.len1-1/2)*Math.cos(this.rot1*Math.PI/180),
            y:this.setY1+this.M*(this.len1-1/2)*Math.sin(this.rot1*Math.PI/180)
        }
        this.setX2=this.endPosition.x;     //將XY2設為通道2的結束，通道3的開始
        this.setY2=this.endPosition.y;


        this.map_x=Math.round((Math.random()*20+3)); //產生移動通道的結尾
        this.setX3=this.map_x*60;
        this.setY3=this.setY2;
        this.len2=Math.round(Math.sqrt(Math.pow(this.setX2-this.setX3,2)+Math.pow(this.setY2-this.setY3,2))/60);
        if(this.setX3>this.setX2){
            this.rot2=0;
        }
        else{
            this.rot2=180;
        }


        this.rot_df=this.rot2-this.rot1;  //計算兩通道間的斜率差 ,如果小於0就補360
        if(this.rot_df<0){
            this.rot_df=this.rot_df+360;
        }

        while(this.len2<5){
            this.map_x=Math.round((Math.random()*20+3));
            this.setX3=this.map_x*60;
            this.setY3=this.setY2;
            this.len2=Math.round(Math.sqrt(Math.pow(this.setX2-this.setX3,2))/60);

            if(this.setX3>this.setX2){
                this.rot2=0;
            }
            else{
                this.rot2=180;
            }

        }

        this.calculate_T_M_differ();     //計算通道之間的偏移

        this.len2=this.map.check(this.endPosition.x,this.endPosition.y,this.len2,this.rot2);    //把通道參數丟進map陣列檢查

        this.gameTunnel[2]=new MovingTunnel();
        this.gameTunnel[2].get(this.endPosition.x,this.setX3);
        this.gameTunnel[2].load((this.endPosition.x+this.setX3)/2,this.endPosition.y,1);
        this.rootScene.attach(this.gameTunnel[2].blockPic);



////////////////////////////以下為通道4~n的生成

        for(i=3;i<this.t_n;i++){


            this.setX1=this.endPosition.x;     //將通道3設為新的起始
            this.setY1=this.endPosition.y;
            this.len1=this.len2;
            this.rot1=this.rot2;

            this.endPosition={                      //以this.setXY為基準計算通道末端位置
                x:this.setX1+this.M*(this.len1-1/2)*Math.cos(this.rot1*Math.PI/180),
                y:this.setY1+this.M*(this.len1-1/2)*Math.sin(this.rot1*Math.PI/180)
            }
            this.setX2=this.endPosition.x;     //將XY2設為通道2的結束，通道3的開始
            this.setY2=this.endPosition.y;


        ////////////////以下產生隨機的第三點計算新的通道參數///////////////////

            this.map_x=Math.round((Math.random()*20+3));
            this.map_y=Math.round((Math.random()*10+4));
            this.setX3=this.map_x*60;
            this.setY3=this.map_y*60;
            this.len2=Math.round(Math.sqrt(Math.pow(this.setX2-this.setX3,2)+Math.pow(this.setY2-this.setY3,2))/60);
            this.rot2=360-Math.atan2(this.setY2-this.setY3,-this.setX2+this.setX3)*180/Math.PI;


            this.rot_df=this.rot2-this.rot1;  //計算兩通道間的斜率差 ,如果小於0就補360
            if(this.rot_df<0){
                this.rot_df=this.rot_df+360;
            }

            while(this.rot_df<90 || this.rot_df>270 || (this.rot_df>140&&this.rot_df<220) || this.len2<5){
                this.map_x=Math.round((Math.random()*20+3));
                this.map_y=Math.round((Math.random()*10+4));
                this.setX3=this.map_x*60;
                this.setY3=this.map_y*60;
                this.len2=Math.round(Math.sqrt(Math.pow(this.setX2-this.setX3,2)+Math.pow(this.setY2-this.setY3,2))/60);
                this.rot2=360-Math.atan2(this.setY2-this.setY3,-this.setX2+this.setX3)*180/Math.PI;

                this.rot_df=this.rot2-this.rot1;  //計算兩通道間的斜率差 ,如果小於0就補360
                if(this.rot_df<0){
                    this.rot_df=this.rot_df+360;
                }
            }


        ////////////////以上產生隨機的第三點計算新的通道參數///////////////////


            this.calculate_T12_differ();     //計算通道之間的偏移


            this.len2=this.map.check(this.endPosition.x,this.endPosition.y,this.len2,this.rot2);    //把通道參數丟進map陣列檢查
        ////////Load新生通道/////////
            this.gameTunnel[i]=new GameGTunnel(this.len2); 
            this.gameTunnel[i].load(this.endPosition.x,this.endPosition.y,this.rot2);
            this.rootScene.attach(this.gameTunnel[i]);


        }


////////////////////////////以上為通道3~n的生成//////////////////////////////////////////



        this.goalPosition={                      //計算通道2末端位置
            x:this.endPosition.x+this.M*(this.len2-1/2)*Math.cos(this.rot2*Math.PI/180),
            y:this.endPosition.y+this.M*(this.len2-1/2)*Math.sin(this.rot2*Math.PI/180)
        }



        ////////Load終點/////////
        this.goalpic = new GoalSign();
        this.goalpic.load(this.goalPosition.x,this.goalPosition.y);
        this.rootScene.attach(this.goalpic.goalPic);

        
        this.rootScene.attach(this.mousepic.mousePic); //滑鼠圖形跟開始標語最後貼
        this.rootScene.attach(this.startpic.startPic);
        

        ////////Load過關畫面，但先不貼出圖/////////
        this.endScene=new EndScene();
        this.endScene.load();
        this.rootScene.attach(this.endScene.clearPic);


        ////////Load死亡畫面，但先不貼出圖/////////
        this.overScene=new OverScene();
        this.overScene.load();
        this.rootScene.attach(this.overScene.clearPic);

        ////////Load倒數計時器/////////
        this.timer=new Timer();
        this.timer.load();
        for(i=0;i<10;i++){
            this.rootScene.attach(this.timer.digitPic1[i]);
            this.rootScene.attach(this.timer.digitPic2[i]);
        }




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



    calculate_T12_differ:function(){

        this.rot_df=this.rot2-this.rot1;  //計算兩通道間的斜率差 ,如果小於0就補360
        if(this.rot_df<0){
            this.rot_df=this.rot_df+360;
        }


        if(this.rot_df>0 && this.rot_df<=90 || this.rot_df>90 && this.rot_df<180 ){
            this.rotat_position1={        //把通道1最右上點的旋轉座標算出來
                x:30*Math.sin((this.rot1)*Math.PI/180)+this.endPosition.x,
                y:-30*Math.cos((this.rot1)*Math.PI/180)+this.endPosition.y
            }
        }
        else if(this.rot_df>=180 && this.rot_df<270  || this.rot_df>=270 && this.rot_df<360){
            this.rotat_position1={        //把通道1最右下點的旋轉座標算出來 (先做右上測試)
                x:-30*Math.sin((this.rot1)*Math.PI/180)+this.endPosition.x,
                y:30*Math.cos((this.rot1)*Math.PI/180)+this.endPosition.y
            }
        }


        this.dx= -30;  //通道2左側點與通道基準座標差值
        if(this.rot_df>0 && this.rot_df<=90 || this.rot_df>=180 && this.rot_df<=270){    //依照情況不同決定用左上或左下點的差值
            this.dy= -30;
        }
        else if(this.rot_df>90 && this.rot_df<180 || this.rot_df>270 && this.rot_df<360){
            this.dy= 30;
        }
        

        this.rotat_position2={        //把通道2左上點跟this.endPosition相對的旋轉座標算出來
            x:this.dx*Math.cos((this.rot2)*Math.PI/180)-this.dy*Math.sin((this.rot2)*Math.PI/180)+this.endPosition.x,
            y:this.dy*Math.cos((this.rot2)*Math.PI/180)+this.dx*Math.sin((this.rot2)*Math.PI/180)+this.endPosition.y
        }


        if(this.rot_df>0 && this.rot_df<=90 || this.rot_df>90 && this.rot_df<180 ){
            this.sub={    //把通道2旋轉基準點與通道1右上點差值計算出來
                x:this.rotat_position2.x-this.rotat_position1.x,
                y:this.rotat_position2.y-this.rotat_position1.y
            }
        }
        else if(this.rot_df>=180 && this.rot_df<270  || this.rot_df>=270 && this.rot_df<360){
            this.sub={    //把通道2旋轉基準點與通道1右下點差值計算出來
                x:this.rotat_position2.x-this.rotat_position1.x,
                y:this.rotat_position2.y-this.rotat_position1.y
            }
        }
        

        this.endPosition.x=this.endPosition.x-this.sub.x;   //利用前面算出的差值平移通道2的基準點
        this.endPosition.y=this.endPosition.y-this.sub.y;
    },

    calculate_T_M_differ:function(){

        this.rot_df=this.rot2-this.rot1;  //計算兩通道間的斜率差 ,如果小於0就補360
        if(this.rot_df<0){
            this.rot_df=this.rot_df+360;
        }


        if(this.rot_df>0 && this.rot_df<=90 || this.rot_df>90 && this.rot_df<180 ){
            this.rotat_position1={        //把通道1最右上點的旋轉座標算出來
                x:30*Math.sin((this.rot1)*Math.PI/180)+this.endPosition.x,
                y:-30*Math.cos((this.rot1)*Math.PI/180)+this.endPosition.y
            }
        }
        else if(this.rot_df>=180 && this.rot_df<270  || this.rot_df>=270 && this.rot_df<360){
            this.rotat_position1={        //把通道1最右下點的旋轉座標算出來 (先做右上測試)
                x:30*Math.sin((this.rot1)*Math.PI/180)+this.endPosition.x,
                y:30*Math.cos((this.rot1)*Math.PI/180)+this.endPosition.y
            }
        }


        this.dx=-60;  //通道2左側點與通道基準座標差值
        if(this.rot_df>0 && this.rot_df<=90 || this.rot_df>=180 && this.rot_df<=270){    //依照情況不同決定用左上或左下點的差值
            this.dy= -30;
        }
        else if(this.rot_df>90 && this.rot_df<180 || this.rot_df>270 && this.rot_df<360){
            this.dy= 30;
        }
        

        this.rotat_position2={        //把通道2左上點跟this.endPosition相對的旋轉座標算出來
            x:this.dx*Math.cos((this.rot2)*Math.PI/180)-this.dy*Math.sin((this.rot2)*Math.PI/180)+this.endPosition.x,
            y:this.dy*Math.cos((this.rot2)*Math.PI/180)+this.dx*Math.sin((this.rot2)*Math.PI/180)+this.endPosition.y
        }


        if(this.rot_df>0 && this.rot_df<=90 || this.rot_df>90 && this.rot_df<180 ){
            this.sub={    //把通道2旋轉基準點與通道1右上點差值計算出來
                x:this.rotat_position2.x-this.rotat_position1.x,
                y:this.rotat_position2.y-this.rotat_position1.y
            }
        }
        else if(this.rot_df>=180 && this.rot_df<270  || this.rot_df>=270 && this.rot_df<360){
            this.sub={    //把通道2旋轉基準點與通道1右下點差值計算出來
                x:this.rotat_position2.x-this.rotat_position1.x,
                y:this.rotat_position2.y-this.rotat_position1.y
            }
        }
        

        this.endPosition.x=this.rotat_position1.x;   //利用前面算出的差值平移通道2的基準點
        this.endPosition.y=this.endPosition.y-this.sub.y;
    },

    initialize: function() {
        ////////滑鼠圖形重設/////////
        this.mousepic.initialize();

        ////////破關圖或失敗圖重設/////////
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

        this.gameTunnel[2].update();


        if(this.mousepic.isStart){
            this.timer.update();  //倒數計時器
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

            for(j=0;j<this.t_n;j++){          //利用j迴圈做or運算
                this.isOut=!(this.gameTunnel[j].covered(this.surround_position.x,this.surround_position.y));
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