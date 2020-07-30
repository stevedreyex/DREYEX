var MovingTunnel=Framework.exClass({  
	

    get:function(swp_x1,swp_x2){    //設定擺盪兩端點數值
        this.swP1=swp_x1;
        this.swP2=swp_x2;

        if(this.swP1<this.swP2){
            this.swP1=swp_x2;
            this.swP2=swp_x1;
        }

        //this.len=swp_l;
    },

    

    load:function(px,py,spd){     //設定圖片起始位置
        this.blockPic = new Framework.Sprite(define.imagePath + 'tunnel2.png');  //宣告圖片
        this.blockPic.position={                                             //起始位置
            x:px,
            y:py
        };
        this.isStop=false;
        this.counter=0;

        

        this.speed=spd;
	},

	update:function() {
		if(!this.isStop && this.swP1<this.blockPic.lowerRight.x){    //一旦移動到邊界就改變方向
			this.speed=-1*this.speed;
            this.isStop=true;
		}
		else if(!this.isStop && this.swP2>this.blockPic.upperLeft.x){
			this.speed=-1*this.speed;
            this.isStop=true;
		}

        this.stop_moving();
        
        if(!this.isStop){
            this.blockPic.position.x=this.blockPic.position.x+this.speed;
        }
		
	},

    stop_moving:function(){    //計時控制通道暫停
        if(this.isStop){
            this.counter++;
            if(this.counter>119){
                this.counter=0;
                this.isStop=false;
                this.blockPic.position.x=this.blockPic.position.x+this.speed;
            }
        }
        
    },

	covered:function(target_x,target_y){    //實為判斷是否cover
		this.surround_position={
            x:target_x,
            y:target_y
        }

        if(this.blockPic.upperLeft.y > this.surround_position.y ||         //如果周邊任何一點超出就傳false
            this.blockPic.lowerLeft.y <  this.surround_position.y || 
            this.blockPic.upperLeft.x > this.surround_position.x ||      ////這裡的碰撞邊界是暫時固定
            this.blockPic.upperRight.x < this.surround_position.x)
            {
                return false;
            }

        return true;

	}


});