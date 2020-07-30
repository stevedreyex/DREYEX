var MovingBlock=Framework.exClass({
	load:function(px,py){
        this.blockPic = new Framework.Sprite(define.imagePath + 'block.png');  //宣告圖片
        this.blockPic.position={                                             //起始位置
            x:px,
            y:py
        };
        this.speed=1;
        this.swing_position={
        	x:px,
            y:py+90
        }
	},

	update: function() {
		if(this.swing_position.y+180<this.blockPic.lowerLeft.y){
			this.speed=-1;
		}
		else if(this.swing_position.y-180>this.blockPic.upperLeft.y){
			this.speed=1;
		}


		this.blockPic.position.y=this.blockPic.position.y+this.speed;

	},

	collide:function(target){
		 for(i=0;i<360;i=i+3){

			this.surround_position={             //運算出圖形周邊各點的位置
		    	x:target.position.x+15*Math.cos(i*Math.PI/180),
		    	y:target.position.y+15*Math.sin(i*Math.PI/180)
			};

			if(this.blockPic.upperLeft.y <= this.surround_position.y &&
            	this.blockPic.lowerLeft.y >= this.surround_position.y &&
            	this.blockPic.upperLeft.x <= this.surround_position.x &&
            	this.blockPic.lowerRight.x >= this.surround_position.x) {

            	return true;
        	}
    	}
	}


});