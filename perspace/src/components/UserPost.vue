<template>
    <div class="card">
        <div class="card-body">
            <div class="form-floating">
                <textarea
                    class="form-control"
                    placeholder="Leave a comment here"
                    id="floatingTextarea2"
                    style="height: 150px"
                    v-model="content"
                ></textarea>
                <label for="floatingTextarea2">write your xinqing</label>
            </div>
            <button @click="post_a_post" type="button" class="btn btn-primary">
                发帖
            </button>
        </div>
    </div>
</template>

<script>
import $ from 'jquery'
import { ref } from "vue";
import { useStore } from "vuex";

export default {
    name: "UserPost",
    setup(props, context) {
        let content = ref("");
        const store = useStore();

        const post_a_post = () => {
            $.ajax({
                url: "https://app165.acapp.acwing.com.cn/myspace/post/",
                type: "POST",
                data: {
                    content: content.value,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.access,
                },
                success(resp) {
                    if (resp.result === "success") {
                        context.emit("post_a_post", content.value);
                        content.value = "";
                    }
                },
            }); 
        };
        return {
            content,
            post_a_post,
        };
    },
};
</script>

<style scoped>
button {
    margin-top: 6px;
    width: 100%;
}
</style>
