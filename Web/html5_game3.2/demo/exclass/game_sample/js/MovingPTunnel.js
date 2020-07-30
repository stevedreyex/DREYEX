var MovingPTunnel=Framework.exClass(MovingTunnel,{  
	

    load:function(px,py,spd){     //設定圖片起始位置
        this.blockPic = new Framework.Sprite(define.imagePath + 'tunnel3.png');  //宣告圖片
        this.blockPic.position={                                             //起始位置
            x:px,
            y:py
        };
        this.isStop=false;
        this.counter=0;


        this.speed=spd;
	},

	update:function() {
		if(!this.isStop && this.swP1<this.blockPic.lowerRight.y){    //一旦移動到邊界就改變方向
			this.speed=-this.speed;
            this.isStop=true;
		}
		else if(!this.isStop && this.swP2>this.blockPic.upperLeft.y){
			this.speed=-this.speed;
            this.isStop=true;
		}

        this.stop_moving();
        
        if(!this.isStop){
            this.blockPic.position.y=this.blockPic.position.y+this.speed;
        }
		
	},
    stop_moving:function(){    //計時控制通道暫停
        if(this.isStop){
            this.counter++;
            if(this.counter>119){
                this.counter=0;
                this.isStop=false;
                this.blockPic.position.y=this.blockPic.position.y+this.speed;
            }
        }
        
    }


});