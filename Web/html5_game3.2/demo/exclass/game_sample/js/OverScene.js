var OverScene=Framework.exClass(EndScene,{
    load:function(){
        this.clearPic = new Framework.Sprite(define.imagePath + 'over.bmp');  //宣告圖片

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

	



	draw:function(ctx){
		//parentCtx.fillStyle = (this.secondHandRotationRate > 0)?'green':'red'; 
        //parentCtx.fillRect(Framework.Game.getCanvasWidth()/2 , Framework.Game.getCanvasHeight()/2, 260, 90);  
        ctx.font = '65pt bold';
        ctx.fillStyle = 'white';
        ctx.textBaseline = 'top';
        ctx.textAlign = 'center';
        ctx.fillText('Menu', this.btn1_position.x, this.btn1_position.y, 260);
        ctx.fillText('Retry', this.btn2_position.x, this.btn2_position.y, 200);
	},


});