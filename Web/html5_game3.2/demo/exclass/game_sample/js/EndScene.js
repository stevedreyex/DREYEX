var EndScene=Framework.exClass({
    load:function(){
        this.clearPic = new Framework.Sprite(define.imagePath + 'clear.bmp');  //宣告圖片

        this.clearPic.position={                                             //起始位置
            x:Framework.Game.getCanvasWidth()+1000,
            y:Framework.Game.getCanvasHeight()/2
        }

        this.btn1_position={
            x:Framework.Game.getCanvasWidth()/2,
            y:Framework.Game.getCanvasHeight()/2
        }
        this.btn2_position={
            x:Framework.Game.getCanvasWidth()/2,
            y:Framework.Game.getCanvasHeight()/2+150
        }
    },

	



	initialize:function(){
        this.clearPic.position={
            x:Framework.Game.getCanvasWidth()+1000,
            y:Framework.Game.getCanvasHeight()/2
        };
    },

	update:function() {
		if(this.clearPic.position.x>Framework.Game.getCanvasWidth()/2){

			this.clearPic.position.x=this.clearPic.position.x-50;
		}

	},

	draw:function(ctx){
		//parentCtx.fillStyle = (this.secondHandRotationRate > 0)?'green':'red'; 
        //parentCtx.fillRect(Framework.Game.getCanvasWidth()/2 , Framework.Game.getCanvasHeight()/2, 260, 90);  
        ctx.font = '65pt bold';
        ctx.fillStyle = 'white';
        ctx.textBaseline = 'top';
        ctx.textAlign = 'center';
        ctx.fillText('Go to next Stage', this.btn1_position.x, this.btn1_position.y, 260);
        ctx.fillText('Retry', this.btn2_position.x, this.btn2_position.y, 200);
	},

	btn1_clicked:function(e) {        ////////////當滑鼠點到Go to next stage就回傳true
        this.previousTouch = { x: e.x, y: e.y };
        if (this.previousTouch.x > this.btn1_position.x-130 && this.previousTouch.x < this.btn1_position.x+130 && this.previousTouch.y > this.btn1_position.y && this.previousTouch.y < this.btn1_position.y+100) {
            return true;
        }
    },

    btn2_clicked:function(e) {        ////////////當滑鼠點到Retry就回傳true
        this.previousTouch = { x: e.x, y: e.y };
        if (this.previousTouch.x > this.btn1_position.x-100 && this.previousTouch.x < this.btn1_position.x+100 && this.previousTouch.y > this.btn1_position.y+150 && this.previousTouch.y < this.btn1_position.y+250) {
            return true;
        }
    }

});