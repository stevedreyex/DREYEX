var GameTunnel=function(start,end){
	this.M=60;

	this.St=start;
	this.Ed=end;

	this.position={
		x:836,
		y:308
	};


	this.load=function(){
		this.tunnelPic=new Framework.Sprite(define.imagePath + 'tunnel1.png');
	};

	this.initialize=function(){

	};

	this.update=function(){

	};

	this.draw=function(ctx){
		
		for(i=0;i<17;i++){
			var picPosition={
				x:this.position.x+(this.M*i),
				y:this.position.y
			}
			this.tunnelPic.position=picPosition;
			this.tunnelPic.draw(ctx);
		}

	};

	this.covered = function(target) {

        for(i=0;i<360;i=i+3){
        	this.surround_position={             //運算出圖形周邊各點的位置
                x:target.position.x+15*Math.cos(i*Math.PI/180),
                y:target.position.y+15*Math.sin(i*Math.PI/180)
            };

            if(this.tunnelPic.upperLeft.y > this.surround_position.y ||         //如果周邊任何一點超出就傳false
           	   this.tunnelPic.lowerLeft.y <  this.surround_position.y ||
               this.St > this.surround_position.x ||
               this.Ed < this.surround_position.x)
               {

            		return false;
        	}

        }

        return true;


        
    };


};