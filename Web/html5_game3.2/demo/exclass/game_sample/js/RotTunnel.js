var RotTunnel=function(spd){
	this.MW=300;
	this.MH=60;

	this.speed=spd;

	this.position={
		x:0,
		y:0
	};

	this.rotation=0;
	this.stop_point=[];
	this.P_i=0;

	this.load=function(set_x,set_y,set_rot){
		this.tunnelPic=new Framework.Sprite(define.imagePath + 'tunnel4.png');
		this.position={
			x:set_x+this.MW/2,
			y:set_y
		};
		this.tunnelPic.position=this.position;
		this.rotation=set_rot;
		this.tunnelPic.rotation=this.rotation;

		this.isStop=false;
		this.counter=0;
	};


	this.initialize=function(){

	};

	this.get_stopP=function(rot){
		
		this.stop_point[this.P_i]=rot;
		this.P_i=this.P_i+1;
	};

	this.update=function(){
		

		if(!this.isStop){
			this.rotation=this.rotation+this.speed;

			for(i=0;i<this.P_i;i++){
				if(this.rotation>=this.stop_point[i] &&this.rotation<=this.stop_point[i]+0.6){
					this.isStop=true;
					break;
				}
				else{
					this.isStop=false;
				}
			}
		}

		if(this.rotation>=360){
			this.rotation=0;
		}

		this.stop_moving();


		this.tunnelPic.rotation=this.rotation;

	};

	this.draw=function(ctx){
		

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

            if(this.position.y-this.MH/2 > this.rotat_position.y ||         //如果周邊任何一點超出就傳false
           	   this.position.y+this.MH/2 <  this.rotat_position.y || 
               this.position.x-this.MW/2 > this.rotat_position.x ||      ////這裡的碰撞邊界是暫時固定
               this.position.x+this.MW/2 < this.rotat_position.x)
               {

            		return false;
        	}

        

        return true;


        
    };


    this.stop_moving=function(){    //計時控制通道暫停
        if(this.isStop){
            this.counter++;
            if(this.counter>119){
                this.counter=0;
                this.isStop=false;
                this.rotation=this.rotation+this.speed;
            }
        }
        
    }



};