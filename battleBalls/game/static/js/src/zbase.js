export class AcGame {
    constructor(id) {
        this.$ac_game = $('#' + id);
        this.ac_game_menu = new AcGameMenu(this);

        this.playground = new AcGamePlayground(this);

        this.start();
    }

    start() {

    }
}