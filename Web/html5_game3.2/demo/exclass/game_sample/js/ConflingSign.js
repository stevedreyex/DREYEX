var ConflingSign=Framework.exClass(SelectSign,{
	load:function(){
        this.bottonPic = new Framework.Sprite(define.imagePath + 'confling.bmp');  //宣告圖片
        this.bottonPic.position={                                             //起始位置
            x:Framework.Game.getCanvasWidth()/2,
            y:Framework.Game.getCanvasHeight()/2+200
        };

        this.isCall=false;

	},



});