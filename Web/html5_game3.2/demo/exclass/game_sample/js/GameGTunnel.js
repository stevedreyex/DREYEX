var GameGTunnel=function(len){
	this.M=60;

	this.len_i=len;

	this.position={
		x:0,
		y:0
	};

	this.rotation=0;

	this.load=function(set_x,set_y,set_rot){
		this.tunnelPic=new Framework.Sprite(define.imagePath + 'tunnel1.png');
		this.position={
			x:set_x,
			y:set_y
		};
		this.rotation=set_rot;
	};


	this.initialize=function(){

	};

	this.update=function(){

	};

	this.draw=function(ctx){
		
		for(i=0;i<this.len_i;i++){
			var picPosition={                      //以this.position為基準對每一張貼出的圖像作偏移
				x:this.position.x+(this.M*i)*Math.cos(this.rotation*Math.PI/180),
				y:this.position.y+(this.M*i)*Math.sin(this.rotation*Math.PI/180)
			}
			this.tunnelPic.position=picPosition;
			this.tunnelPic.rotation=this.rotation;
			this.tunnelPic.draw(ctx);
		}

	};

	this.covered = function(target_x,target_y) {
			this.surround_position={
				x:target_x,
				y:target_y
			}

            this.dx=this.surround_position.x-this.position.x;
            this.dy=this.surround_position.y-this.position.y;


            this.rotat_position={        //把周邊點跟this.position相對的旋轉座標算出來
            	x:this.dx*Math.cos((360-this.rotation)*Math.PI/180)-this.dy*Math.sin((360-this.rotation)*Math.PI/180)+this.position.x,
            	y:this.dy*Math.cos((360-this.rotation)*Math.PI/180)+this.dx*Math.sin((360-this.rotation)*Math.PI/180)+this.position.y
            }

            if(this.position.y-this.M/2 > this.rotat_position.y ||         //如果周邊任何一點超出就傳false
           	   this.position.y+this.M/2 <  this.rotat_position.y || 
               this.position.x-this.M/2 > this.rotat_position.x ||      ////這裡的碰撞邊界是暫時固定
               this.position.x+(this.len_i-1/2)*this.M < this.rotat_position.x)
               {

            		return false;
        	}

        

        return true;


        
    };



};